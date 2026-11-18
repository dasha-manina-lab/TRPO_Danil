#ifndef PRIMELIST_H
#define PRIMELIST_H

#include <vector>

// Возвращает все простые числа из отрезка [l, r] по возрастанию.
// Библиотека не взаимодействует с пользователем, поэтому её можно
// использовать без изменений в приложении с графическим интерфейсом.
std::vector<int> primelist(int l, int r);

#endif // PRIMELIST_H
