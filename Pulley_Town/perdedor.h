#ifndef PERDEDOR_H
#define PERDEDOR_H
using namespace std;
#include <QWidget>

namespace Ui {
class Perdedor;
}

class Perdedor : public QWidget
{
    Q_OBJECT

public:
    explicit Perdedor(QWidget *parent = nullptr);
    ~Perdedor();
    void Causa(int _mensaje);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Perdedor *ui;
    QString texto;
};

#endif // PERDEDOR_H
