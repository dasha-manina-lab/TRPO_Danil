# Лабораторная работа № 5

Откройте `primelist_qt.pro` в Qt Creator через **Файл → Открыть файл или проект**. Выберите комплект Desktop Qt с компилятором C++17 (например, Qt MinGW на Windows) и соберите проект. Оставьте включённой сборку перед запуском в настройках Qt Creator.

Общий qmake-проект объявляет `primelist_lib` зависимостью `primelist` и `primelist_gui`. При сборке qmake сначала проверяет библиотеку, затем собирает приложения. После изменения библиотеки оба приложения заново компонуют исполняемые файлы. Сборка создаёт конфигурации Debug и Release за один вызов make.

В каталоге сборки находятся:

- `primelist_lib/debug/` и `primelist_lib/release/` с архивами `libprimelist_lib.a` (MinGW/GCC) или `primelist_lib.lib` (MSVC).
- `primelist/debug/` и `primelist/release/` с консольным приложением.
- `primelist_gui/debug/` и `primelist_gui/release/` с графическим приложением.

В Qt Creator выберите `primelist` в настройках запуска и в поле **Параметры командной строки** введите `1 10`. Программа выведет `2`, `3`, `5`, `7` в стандартный поток вывода. Из терминала можно запустить `primelist.exe 1 10`.

| Код | Результат | Пример аргументов |
| --- | --- | --- |
| 0 | Успех | `1 10` |
| 1 | Не хватает одного или обоих аргументов | `1` |
| 2 | Аргумент не читается целиком как десятичное целое типа `long long` | `1 10abc` |
| 3 | Граница вне диапазона от 1 до `INT_MAX` или B меньше либо равна A | `0 10`, `10 1`, `2 2` |

При ошибке консольное приложение выводит сообщение в стандартный поток ошибок. В Windows CMD код завершения можно увидеть командой `echo %ERRORLEVEL%`, введённой после запуска на отдельной строке.

Для GUI выберите `primelist_gui` в настройках запуска. Проверьте правильный диапазон `1–10`, равные границы `7–7`, обратный порядок `10–1` и нулевую границу `0–10`. Для трёх последних примеров появится диалог с причиной ошибки.

## Перенос в локальные репозитории ЛР4

Откройте CMD в папке с `primelist_qt.pro`. Перед переносом проверьте, что в обоих репозиториях все изменения зафиксированы. Выполняйте команды по одной.

```cmd
git -C primelist fetch https://github.com/dasha-manina-lab/TRPO_Danil.git lab5
git -C primelist diff --quiet HEAD -- main.cpp && (git -C primelist diff c5f3817~1 c5f3817 -- primelist/main.cpp | git -C primelist apply --cached -p2) && git -C primelist restore --worktree -- main.cpp && git -C primelist commit -m "Lab 5: read command-line arguments"
git -C primelist diff --quiet HEAD -- main.cpp && (git -C primelist diff 111c305~1 111c305 -- primelist/main.cpp | git -C primelist apply --cached -p2) && git -C primelist restore --worktree -- main.cpp && git -C primelist commit -m "Lab 5: validate decimal arguments"
git -C primelist diff --quiet HEAD -- main.cpp && (git -C primelist diff df36b17~1 df36b17 -- primelist/main.cpp | git -C primelist apply --cached -p2) && git -C primelist restore --worktree -- main.cpp && git -C primelist commit -m "Lab 5: validate strict range order"
git -C primelist_gui fetch https://github.com/dasha-manina-lab/TRPO_Danil.git lab5
git -C primelist_gui diff --quiet HEAD -- dialog.cpp && (git -C primelist_gui diff 7010d56~1 7010d56 -- primelist_gui/dialog.cpp | git -C primelist_gui apply --cached -p2) && git -C primelist_gui restore --worktree -- dialog.cpp && git -C primelist_gui commit -m "Lab 5: validate strict range order in GUI"
```

Проверьте историю командами `git -C primelist log -4 --oneline` и `git -C primelist_gui log -3 --oneline`.
