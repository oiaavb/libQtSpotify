#include "qspotifyimageprovider.h"
#include "qspotifysession.h"

#include <libspotify/api.h>

QSpotifyImageResponse::QSpotifyImageResponse(const QString &id)
    : m_id(id)
{
    connect(QSpotifySession::instance(), &QSpotifySession::receivedImageResponse,
               this, [&](const QString &id, QImage img)
    {
        if (m_id == id) {
            m_image = img;
            Q_EMIT finished();
        }
    }, Qt::QueuedConnection);
}

QQuickTextureFactory *QSpotifyImageResponse::textureFactory() const
{
    return QQuickTextureFactory::textureFactoryForImage(m_image);
}


QQuickImageResponse* QSpotifyImageProvider::requestImageResponse(const QString &id, const QSize &)
{    
    QSpotifyImageResponse *response = new QSpotifyImageResponse(id);

    QSpotifySession::instance()->requestSpotifyImage(id);

    return response;
}
