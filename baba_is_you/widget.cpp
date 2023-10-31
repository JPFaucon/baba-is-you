#include "widget.h"
#include "gtile.h"
#include "model/direction.h"

Widget::Widget(Game &model, QWidget *parent)
    : QWidget(parent),
    gridLayout_{new QGridLayout},
    model_{model},
    board_{model_.getBoard()},
    nbRows_{board_.getNbRows()},
    nbCols_{board_.getNbCols()},
    gameStarted_{false}
{
    QLabel *welcomeLabel = new QLabel(""
                                      "BABA IS YOU\n\n"
                                      "Flèches pour se déplacer\n"
                                      "N pour une nouvelle partie\n"
                                      "S pour la partie sauvegardée (s'il y en a une)\n"
                                      "R pour recommencer le niveau\n"
                                      "E pour sauvegarder la partie");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    welcomeLabel->setStyleSheet("font-size: 20px; font-weight: bold;");

    QVBoxLayout *welcomeLayout{new QVBoxLayout};
    welcomeLayout->addWidget(welcomeLabel);

    this->setLayout(welcomeLayout);

    gridLayout_->setSpacing(0);
    model_.addObserver(this);
}

Widget::~Widget()
{}

void Widget::update(const Subject * subject)
{
    if (gridLayout_->isEmpty()) {
        createBoard();
    }
    for (unsigned row = 0; row < nbRows_; ++row) {
        for (unsigned column = 0; column < nbCols_; ++column) {
            QLayoutItem* layoutItem = gridLayout_->itemAtPosition(row, column);
            if (layoutItem) {
                GTile *tile = dynamic_cast<GTile*>(layoutItem->widget());
                if (tile) {
                    tile->updateSprite();
                }
            }
        }
    }
    if (model_.getIsWinReached())
    {
        try
        {
            clearGridLayout();
            model_.nextLevel();
        }  catch (std::runtime_error &)
        {
            model_.playLevel(0);
        }
    }
}


/* ************************************ private methods ************************************ */


void Widget::createBoard()
{

    for (unsigned row = 0; row < nbRows_; ++row) {
        for (unsigned column = 0; column < nbCols_; ++column) {
            GTile *tile = new GTile(board_.getTileAt(row, column));
            QSize fixedSize(30, 30);
            tile->setFixedSize(fixedSize);
            gridLayout_->addWidget(tile, row, column);
            tile->updateSprite();
        }
    }
}

void Widget::clearWidget()
{
    QLayoutItem * item;

    while ((item = this->layout()->takeAt(0))) {
        delete item;
    }

    delete this->layout();
}

void Widget::clearGridLayout()
{
    while (QLayoutItem* item = gridLayout_->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            delete widget;
        }
        delete item;
    }
}

void Widget::setGridLayoutInWidget()
{
    if (this->layout() != gridLayout_) {
        clearWidget();
        this->setLayout(gridLayout_);
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) && gameStarted_) {
        if (event->key() == Qt::Key_Left) {
            model_.moveYou(Direction::LEFT);
        } else if (event->key() == Qt::Key_Right) {
            model_.moveYou(Direction::RIGHT);
        } else if (event->key() == Qt::Key_Up) {
            model_.moveYou(Direction::UP);
        } else if (event->key() == Qt::Key_Down) {
            model_.moveYou(Direction::DOWN);
        }

        event->accept();
    } else {
        QString key = event->text().toUpper();

        if (key == "E" && gameStarted_)
        {
            model_.saveLevel();
        }
        else if (key == "N" || key == "S" || key == "R")
        {
            setGridLayoutInWidget();
            clearGridLayout();
            if (key == "N")
            {
                model_.playLevel(0);
                gameStarted_ = true;
            }
            else if (key == "S")
            {
                try
                {
                    model_.playSavedLevel();
                    gameStarted_ = true;
                }
                catch (std::invalid_argument&){}
            }
            else if (key == "R" && gameStarted_)
            {
                model_.reset();
            }
        }
        else
        {
            QWidget::keyPressEvent(event);
        }
    }
}
