/**
* @file
*
* @section LICENSE
*
* OsmAnd - Android navigation software based on OSM maps.
* Copyright (C) 2010-2013  OsmAnd Authors listed in AUTHORS file
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __MODEL_MAP_OBJECT_H_
#define __MODEL_MAP_OBJECT_H_

#include <stdint.h>

#include <QList>
#include <QMap>
#include <QVector>
#include <QString>

#include <OsmAndCore.h>
#include <Area.h>

namespace OsmAnd {

    class ObfMapSection;

    namespace Model {

        class OSMAND_CORE_API MapObject
        {
        private:
        protected:
            MapObject();

            uint64_t _id;
            bool _isArea;
            QVector< PointI > _coordinates;
            QList< QVector< PointI > > _polygonInnerCoordinates;
            QList<uint32_t> _types;
            QList<uint32_t> _extraTypes;
            QMap<uint32_t, QString> _names;
        public:
            virtual ~MapObject();

            const uint64_t& id;
            const QMap<uint32_t, QString>& names;

            friend class ObfMapSection;
        };

    } // namespace Model

} // namespace OsmAnd

#endif // __MODEL_MAP_OBJECT_H_