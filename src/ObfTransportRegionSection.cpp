#include "ObfTransportRegionSection.h"

#include <QtEndian>
#include <ObfReader.h>
#include <google/protobuf/wire_format_lite.h>

#include "../native/src/proto/osmand_odb.pb.h"

OsmAnd::ObfTransportRegionSection::ObfTransportRegionSection()
    : _top(0)
    , _left(0)
    , _bottom(0)
    , _right(0)
    , _stopsFileOffset(0)
    , _stopsFileLength(0)
{
}

void OsmAnd::ObfTransportRegionSection::read( gpb::io::CodedInputStream* cis, ObfTransportRegionSection* section )
{
    for(;;)
    {
        auto tag = cis->ReadTag();
        switch(gpb::internal::WireFormatLite::GetTagFieldNumber(tag))
        {
        case 0:
            return;
        case OsmAndTransportIndex::kRoutesFieldNumber:
            ObfReader::skipUnknownField(cis, tag);
            break;
        case OsmAndTransportIndex::kNameFieldNumber:
            cis->ReadString(&section->_name, std::numeric_limits<int>::max());
            break;
        case OsmAndTransportIndex::kStopsFieldNumber:
            {
                gpb::uint32 length;
                cis->ReadRaw(&length, sizeof(length));
                section->_stopsFileLength = qFromBigEndian(length);
                section->_stopsFileOffset = cis->TotalBytesRead();
                auto oldLimit = cis->PushLimit(section->_stopsFileLength);
                readTransportBounds(cis, section);
                cis->PopLimit(oldLimit);
            }
            break;
        case OsmAndTransportIndex::kStringTableFieldNumber:
            {
                gpb::uint32 length;
                cis->ReadVarint32(&length);
                auto offset = cis->TotalBytesRead();
                cis->Seek(offset + length);
            }
            //TODO:
            /*IndexStringTable st = new IndexStringTable();
            st.length = codedIS.readRawVarint32();
            st.fileOffset = codedIS.getTotalBytesRead();
            // Do not cache for now save memory
            // readStringTable(st, 0, 20, true);
            ind.stringTable = st;
            codedIS.seek(st.length + st.fileOffset);*/
            break;
        default:
            ObfReader::skipUnknownField(cis, tag);
            break;
        }
    }
}

void OsmAnd::ObfTransportRegionSection::readTransportBounds( gpb::io::CodedInputStream* cis, ObfTransportRegionSection* section )
{
    for(;;)
    {
        auto tag = cis->ReadTag();
        switch(gpb::internal::WireFormatLite::GetTagFieldNumber(tag))
        {
        case 0:
            return;
        case TransportStopsTree::kLeftFieldNumber:
            cis->ReadVarint32(reinterpret_cast<gpb::uint32*>(&section->_left));
            break;
        case TransportStopsTree::kRightFieldNumber:
            cis->ReadVarint32(reinterpret_cast<gpb::uint32*>(&section->_right));
            break;
        case TransportStopsTree::kTopFieldNumber:
            cis->ReadVarint32(reinterpret_cast<gpb::uint32*>(&section->_top));
            break;
        case TransportStopsTree::kBottomFieldNumber:
            cis->ReadVarint32(reinterpret_cast<gpb::uint32*>(&section->_bottom));
            break;
        default:
            ObfReader::skipUnknownField(cis, tag);
            break;
        }
    }
}

