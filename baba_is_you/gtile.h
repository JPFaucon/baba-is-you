#ifndef GTILE_H
#define GTILE_H

#include <QLabel>
#include "model/tile.h"

/*!
 * \brief The GTile class represents one graphical tile. It
 * displays the top component that the tile contains.
 */
class GTile: public QLabel
{

    Q_OBJECT

protected:
    /*!
     * \brief tile_ The corresponding tile to that graphical tile.
     */
    const Tile &tile_;

public:
    explicit GTile(const Tile &tile, QLabel * parent = nullptr);

    /*!
     * \brief updateSprite Updates the image/sprite for that tile.
     */
    void updateSprite();

};

#endif // GTILE_H
