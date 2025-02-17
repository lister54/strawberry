/*
 * Strawberry Music Player
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

#ifndef TIDALBASEREQUEST_H
#define TIDALBASEREQUEST_H

#include "config.h"

#include <QtGlobal>
#include <QObject>
#include <QSet>
#include <QList>
#include <QPair>
#include <QVariant>
#include <QByteArray>
#include <QString>
#include <QStringList>
#include <QUrl>
#include <QSslError>
#include <QJsonObject>
#include <QJsonValue>

#include "includes/shared_ptr.h"
#include "tidalservice.h"

class QNetworkReply;
class NetworkAccessManager;

class TidalBaseRequest : public QObject {
  Q_OBJECT

 public:
  explicit TidalBaseRequest(TidalService *service, const SharedPtr<NetworkAccessManager> network, QObject *parent = nullptr);

  enum class Type {
    None,
    FavouriteArtists,
    FavouriteAlbums,
    FavouriteSongs,
    SearchArtists,
    SearchAlbums,
    SearchSongs,
    StreamURL
  };

 protected:
  using Param = QPair<QString, QString>;
  using ParamList = QList<Param>;

  QNetworkReply *CreateRequest(const QString &ressource_name, const ParamList &params_provided);
  QByteArray GetReplyData(QNetworkReply *reply);
  QJsonObject ExtractJsonObj(const QByteArray &data);
  QJsonValue ExtractItems(const QByteArray &data);
  QJsonValue ExtractItems(const QJsonObject &json_obj);

  virtual void Error(const QString &error, const QVariant &debug = QVariant()) = 0;
  static QString ErrorsToHTML(const QStringList &errors);

  QString client_id() const { return service_->client_id(); }
  quint64 user_id() const { return service_->user_id(); }
  QString country_code() const { return service_->country_code(); }
  QString quality() const { return service_->quality(); }
  int artistssearchlimit() const { return service_->artistssearchlimit(); }
  int albumssearchlimit() const { return service_->albumssearchlimit(); }
  int songssearchlimit() const { return service_->songssearchlimit(); }
  QString token_type() const { return service_->token_type(); }
  QString access_token() const { return service_->access_token(); }
  bool authenticated() const { return service_->authenticated(); }

 private Q_SLOTS:
  void HandleSSLErrors(const QList<QSslError> &ssl_errors);

 private:
  TidalService *service_;
  const SharedPtr<NetworkAccessManager> network_;
};

#endif  // TIDALBASEREQUEST_H
