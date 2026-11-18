#include "dialog.h"
#include "ui_dialog.h"

#include <QMessageBox>
#include <QString>

#include <algorithm>
#include <climits>

#include "primelist.h"

namespace {

// Преобразует текст поля ввода в натуральное число, помещающееся в int.
// Возвращает пустую строку при успехе, иначе текст причины ошибки.
QString parseNatural(const QString &text, int &value)
{
    const QString s = text.trimmed();
    if (s.isEmpty()) {
        return QObject::tr("поле пустое");
    }

    bool ok = false;
    const qlonglong n = s.toLongLong(&ok, 10);
    if (!ok) {
        return QObject::tr("значение не является десятичным целым числом");
    }
    if (n < 1) {
        return QObject::tr("число должно быть натуральным (не меньше 1)");
    }
    if (n > INT_MAX) {
        return QObject::tr("число слишком большое (максимум %1)").arg(INT_MAX);
    }

    value = static_cast<int>(n);
    return QString();
}

} // namespace

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::calculate()
{
    int a = 0;
    int b = 0;

    const QString errA = parseNatural(ui->lineEditA->text(), a);
    if (!errA.isEmpty()) {
        QMessageBox::critical(this, tr("Ошибка"),
                              tr("Параметр A введён неверно: %1.").arg(errA));
        return;
    }

    const QString errB = parseNatural(ui->lineEditB->text(), b);
    if (!errB.isEmpty()) {
        QMessageBox::critical(this, tr("Ошибка"),
                              tr("Параметр B введён неверно: %1.").arg(errB));
        return;
    }

    // Границы могут быть введены в любом порядке
    if (a > b) {
        std::swap(a, b);
    }

    ui->listWidget->clear();
    for (int n : primelist(a, b)) {
        ui->listWidget->addItem(QString::number(n));
    }
}