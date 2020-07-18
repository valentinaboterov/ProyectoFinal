#ifndef POLEA_H
#define POLEA_H

#include <QWidget>

namespace Ui {
class Polea;
}

class Polea : public QWidget
{
    Q_OBJECT

public:
    explicit Polea(QWidget *parent = nullptr);
    ~Polea();

private:
    Ui::Polea *ui;
};

#endif // POLEA_H
