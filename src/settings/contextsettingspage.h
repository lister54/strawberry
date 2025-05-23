/*
 * Strawberry Music Player
 * This code was part of Clementine.
 * Copyright 2010, David Sansome <me@davidsansome.com>
 * Copyright 2018-2021, Jonas Kvinge <jonas@jkvinge.net>
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

#ifndef CONTEXTSETTINGSPAGE_H
#define CONTEXTSETTINGSPAGE_H

#include "config.h"

#include <QObject>
#include <QHash>
#include <QString>

#include "settingspage.h"

class QAction;
class QCheckBox;

class SettingsDialog;
class Ui_ContextSettingsPage;

class ContextSettingsPage : public SettingsPage {
  Q_OBJECT

 public:
  explicit ContextSettingsPage(SettingsDialog *dialog, QWidget *parent = nullptr);
  ~ContextSettingsPage() override;

  void Load() override;
  void Save() override;

 private Q_SLOTS:
  void InsertVariableFirstLine(QAction *action);
  void InsertVariableSecondLine(QAction *action);
  static void ShowMenuTooltip(QAction *action);
  void HeadlineFontChanged();
  void NormalFontChanged();

 private:
  Ui_ContextSettingsPage *ui_;
  QHash<QString, QCheckBox*> checkboxes_;
};

#endif  // CONTEXTSETTINGSPAGE_H
