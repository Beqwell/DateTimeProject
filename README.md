# DateTimeProject
Посилання на менулий код - https://github.com/tyure/lab_1/blob/main/laber1.cpp

Виконані завдання

 Рефакторинг коду:

1. Розділення існуючого коду на окремі файли заголовків та реалізацій.
2. Використання фабричного методу для створення об'єктів класів `Hour`, `Minute`, `Second`.
3. Виділення логіки валідації дат у окремий клас `DateValidator`.
4. Валідація значень за допомогою винятків.

Написання тестів:

1. Написання unit tests для перевірки коректності роботи класів `Hour`, `Minute`, `Second`, `Date`, `Time`, `DateTime`.
2. Використання Google Test для написання та запуску тестів.
3. Переконання, що всі тести пройшли успішно.

Покращення архітектури:

1. Дотримання принципів ООП, таких як інкапсуляція, поліморфізм.
2. Використання патернів проектування для підвищення гнучкості коду.

 Деталі рефакторингу

1. Використання фабричного методу:

Створено клас `TimeFactory` для створення об'єктів `Hour`, `Minute`, `Second`.

class TimeFactory {
public:
    static Hour createHour(int value) {
        return Hour(value);
    }
    static Minute createMinute(int value) {
        return Minute(value);
    }
    static Second createSecond(int value) {
        return Second(value);
    }
};

2. Валідація через винятки

Методи валідації у класах `Hour`, `Minute`, `Second` були змінені для використання винятків.

class Hour : public TimeUnit {
public:
    Hour(int h) : TimeUnit(h) {}
    void validate() const override {
        if (value < 0 || value >= 24) throw std::invalid_argument("Invalid hour");
    }
};

class Minute : public TimeUnit {
public:
    Minute(int m) : TimeUnit(m) {}
    void validate() const override {
        if (value < 0 || value >= 60) throw std::invalid_argument("Invalid minute");
    }
};

class Second : public TimeUnit {
public:
    Second(int s) : TimeUnit(s) {}
    void validate() const override {
        if (value < 0 || value >= 60) throw std::invalid_argument("Invalid second");
    }
};


3. Виділення валідації у окремий клас:

Створено клас `DateValidator` для валідації дат.


class DateValidator {
public:
    static bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static bool isValidDate(int year, int month, int day) {
        if (year < 0 || month < 1 || month > 12 || day < 1)
            return false;

        const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int maxDays = daysInMonth[month];

        if (month == 2 && isLeapYear(year))
            maxDays = 29;

        return (day <= maxDays);
    }
};


4. Оновлення класу `Date`:

Клас `Date` тепер використовує `DateValidator` для перевірки валідності дат.


struct Date {
    int year;
    int month;
    int day;

    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    bool isValid() const {
        return DateValidator::isValidDate(year, month, day);
    }
};


 Написання тестів

Тести були написані для перевірки функцій валідації та коректності роботи класів.


 Порівняння попередньої та оновленої версій програми

1. Час виконання окремих алгоритмів/функцій:

Порівняння часу виконання старого та нового коду показало, що час виконання основних функцій залишився незмінним, оскільки зміни були зосереджені на структурі та організації коду, а не на алгоритмічній оптимізації.

2. Обсяг коду:

Оновлена версія програми має більш чітку та організовану структуру. Кількість рядків коду дещо зросла через додавання нових класів та методів, але це підвищило читабельність та підтримку коду.

3. Відмінності між старим та новим кодом:

- Структура коду: Код було розбито на окремі файли заголовків та реалізацій для кращої організації.
- Валідація :Валідація значень тепер здійснюється через винятки, що підвищило надійність програми.
- Фабричний метод: Використання фабричного методу для створення об'єктів підвищило гнучкість та розширюваність коду.
- Тестування: Додано unit tests для перевірки коректності функціонування програми.
