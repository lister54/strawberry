/*
 * Strawberry Music Player
 * Copyright 2018-2024, Jonas Kvinge <jonas@jkvinge.net>
 *
 * Strawberry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Strawberry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Strawberry.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef FILTERPARSERUINTEQCOMPARATOR_H
#define FILTERPARSERUINTEQCOMPARATOR_H

#include <QVariant>

#include "filterparsersearchtermcomparator.h"

class FilterParserUIntEqComparator : public FilterParserSearchTermComparator {
 public:
  explicit FilterParserUIntEqComparator(const uint search_term);
  bool Matches(const QVariant &value) const override;
 private:
  uint search_term_;
  Q_DISABLE_COPY(FilterParserUIntEqComparator)
};

#endif  // FILTERPARSERUINTEQCOMPARATOR_H
