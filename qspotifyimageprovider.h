#ifndef QSPOTIFYIMAGEPROVIDER_H
#define QSPOTIFYIMAGEPROVIDER_H

#include <QtQuick/QQuickImageProvider>

class QSpotifyImageResponse : public QQuickImageResponse
{
public:
    QSpotifyImageResponse(const QString &id);
    QQuickTextureFactory * textureFactory() const override;

private:
    QString m_id;
    QImage m_image;
};

class QSpotifyImageProvider : public QQuickAsyncImageProvider
{
public:
    QQuickImageResponse* requestImageResponse(const QString &id, const QSize &requestedSize);
};

#endif // QSPOTIFYIMAGEPROVIDER_H
