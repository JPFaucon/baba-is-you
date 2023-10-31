#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

#include "observer/observer.h"
#include "model/board.h"
#include "model/game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

/*!
 * \brief The Widget class represents a custom QWidget
 * that acts as the main graphical user interface for the game.
 */
class Widget : public QWidget, public Observer
{
    Q_OBJECT
private:
    /*!
     * \brief gridLayout_ Grid to organize the tiles.
     */
    QGridLayout *gridLayout_;

    /*!
     * \brief model_ The model.
     */
    Game &model_;

    /*!
     * \brief board_ The board.
     */
    const Board &board_;

    /*!
     * \brief nbRows_ The number of rows.
     */
    unsigned nbRows_;

    /*!
     * \brief nbCols_ The number of columns.
     */
    unsigned nbCols_;
    bool gameStarted_;

public:
    Widget(Game &model, QWidget *parent = nullptr);

    ~Widget();

    /*!
     * \brief Method called by the model when it is updated.
     * This method updates the display based on changes to the model.
     * \param subject The subject that was updated.
     */
    void update(const Subject * subject) override;


private:
    void createBoard();
    void clearWidget();
    void clearGridLayout();
    void setGridLayoutInWidget();

    void keyPressEvent(QKeyEvent *event) override;
};
#endif // WIDGET_H

