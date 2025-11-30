#include <iostream>
#include <string>
#include <locale>

using namespace std;

class ProductBatch {
protected:
    int quantity;
    string productName;
    int day, month, year;
    int soldQuantity;
    int writtenOffQuantity;

public:

    ProductBatch() : quantity(0), day(0), month(0), year(0), soldQuantity(0), writtenOffQuantity(0) {
        cout << "Вызван конструктор ProductBatch()" << endl;
    }


    void initializeBatch(int qty, const string& name, int d, int m, int y) {
        cout << "Вызван initializeBatch: количество=" << qty << ", товар='" << name
            << "', дата=" << d << "." << m << "." << y << endl;

        quantity = qty;
        productName = name;
        day = d;
        month = m;
        year = y;
        soldQuantity = 0;
        writtenOffQuantity = 0;
    }


    virtual void sellProduct(int qty = 1) {
        cout << "Вызван sellProduct: количество=" << qty << endl;

        if (qty <= 0) {
            cout << "Ошибка: количество должно быть положительным!" << endl;
            return;
        }

        if (qty <= getRemainingQuantity()) {
            soldQuantity += qty;
            cout << "Продано " << qty << " единиц товара" << endl;
        }
        else {
            cout << "Ошибка: недостаточно товара для продажи!" << endl;
        }
    }


    virtual void writeOffProduct(int qty = 1) {
        cout << "Вызван writeOffProduct: количество=" << qty << endl;

        if (qty <= 0) {
            cout << "Ошибка: количество должно быть положительным!" << endl;
            return;
        }

        if (qty <= getRemainingQuantity()) {
            writtenOffQuantity += qty;
            cout << "Списано " << qty << " единиц товара" << endl;
        }
        else {
            cout << "Ошибка: недостаточно товара для списания!" << endl;
        }
    }


    void displayRemaining() {
        cout << "Вызван displayRemaining" << endl;
        int remaining = getRemainingQuantity();
        cout << "Остаток товара '" << productName << "': " << remaining << " шт." << endl;
    }


    virtual void displayFullReport() {
        cout << "Вызван displayFullReport" << endl;
        cout << "=== ПОЛНЫЙ ОТЧЕТ ПО ПАРТИИ ===" << endl;
        cout << "Наименование товара: " << productName << endl;
        cout << "Дата поставки: " << day << "." << month << "." << year << endl;
        cout << "Изначальное количество: " << quantity << " шт." << endl;
        cout << "Продано: " << soldQuantity << " шт." << endl;
        cout << "Списано: " << writtenOffQuantity << " шт." << endl;
        cout << "Остаток: " << getRemainingQuantity() << " шт." << endl;
        cout << "===============================" << endl;
    }


    int getRemainingQuantity() const {
        return quantity - soldQuantity - writtenOffQuantity;
    }


    string getProductName() const { return productName; }
    int getQuantity() const { return quantity; }
    int getSoldQuantity() const { return soldQuantity; }
    int getWrittenOffQuantity() const { return writtenOffQuantity; }
};


class PerishableProduct : public ProductBatch {
private:
    int shelfLife;
    int daysPassed;

public:

    PerishableProduct() : shelfLife(0), daysPassed(0) {
        cout << "Вызван конструктор PerishableProduct()" << endl;
    }


    void initializeBatch(int qty, const string& name, int d, int m, int y, int life) {
        cout << "Вызван initializeBatch PerishableProduct: количество=" << qty
            << ", товар='" << name << "', дата=" << d << "." << m << "." << y
            << ", срок годности=" << life << " дней" << endl;

        ProductBatch::initializeBatch(qty, name, d, m, y);
        shelfLife = life;
        daysPassed = 0;
    }


    void newDay() {
        cout << "Вызван newDay: прошел 1 день" << endl;
        daysPassed++;
        cout << "Прошло дней с поставки: " << daysPassed << endl;

        if (isExpired()) {
            cout << "ВНИМАНИЕ! Товар '" << getProductName() << "' просрочен!" << endl;
        }
    }


    void sellProduct(int qty = 1) override {
        cout << "Вызван sellProduct PerishableProduct: количество=" << qty << endl;

        if (isExpired()) {
            cout << "Ошибка: нельзя продать просроченный товар!" << endl;
            return;
        }

        ProductBatch::sellProduct(qty);
    }


    void displayRemaining() {
        cout << "Вызван displayRemaining PerishableProduct" << endl;
        int remaining = getRemainingQuantity();
        cout << "Остаток товара '" << getProductName() << "': " << remaining << " шт." << endl;
        cout << "Оставшийся срок годности: " << getRemainingShelfLife() << " дней" << endl;

        if (isExpired()) {
            cout << "Товар ПРОСРОЧЕН!" << endl;
        }
    }


    void displayFullReport() override {
        cout << "Вызван displayFullReport PerishableProduct" << endl;
        cout << "=== ПОЛНЫЙ ОТЧЕТ ПО ПАРТИИ (Срок годности) ===" << endl;
        cout << "Наименование товара: " << getProductName() << endl;
        cout << "Дата поставки: " << day << "." << month << "." << year << endl;
        cout << "Изначальное количество: " << getQuantity() << " шт." << endl;
        cout << "Продано: " << getSoldQuantity() << " шт." << endl;
        cout << "Списано: " << getWrittenOffQuantity() << " шт." << endl;
        cout << "Остаток: " << getRemainingQuantity() << " шт." << endl;
        cout << "Срок годности: " << shelfLife << " дней" << endl;
        cout << "Прошло дней: " << daysPassed << endl;
        cout << "Осталось дней: " << getRemainingShelfLife() << endl;
        cout << "Статус: " << (isExpired() ? "ПРОСРОЧЕН" : "Годен") << endl;
        cout << "=============================================" << endl;
    }


    bool isExpired() const {
        return daysPassed > shelfLife;
    }


    int getRemainingShelfLife() const {
        return (shelfLife - daysPassed) > 0 ? (shelfLife - daysPassed) : 0;
    }
};


void testScenario1(PerishableProduct& product) {
    cout << "\n=== ТЕСТ 1: Обычные операции ===" << endl;
    product.initializeBatch(100, "Молоко", 1, 10, 2024, 7);
    product.sellProduct(10);
    product.sellProduct(5);
    product.writeOffProduct(2);
    product.newDay();
    product.newDay();
    product.displayRemaining();
    product.displayFullReport();
}


void testScenario2(PerishableProduct& product) {
    cout << "\n=== ТЕСТ 2: Истекающий срок ===" << endl;
    product.initializeBatch(50, "Йогурт", 1, 10, 2024, 3);
    product.sellProduct(10);
    product.newDay();
    product.newDay();
    product.sellProduct(5);
    product.newDay();
    product.sellProduct(5);
    product.displayFullReport();
}


void testScenario3(PerishableProduct& product) {
    cout << "\n=== ТЕСТ 3: Множественные операции ===" << endl;
    product.initializeBatch(200, "Сыр", 1, 10, 2024, 10);
    for (int i = 0; i < 5; i++) {
        product.newDay();
    }
    product.sellProduct(20);
    product.sellProduct(30);
    product.writeOffProduct(5);
    product.writeOffProduct(10);
    product.displayRemaining();
    product.displayFullReport();
}


void inputProductData(PerishableProduct& product) {
    int quantity, day, month, year, shelfLife;
    string name;

    cout << "\n=== ВВОД ДАННЫХ ПАРТИИ ===" << endl;
    cout << "Введите наименование товара: ";
    cin.ignore();
    getline(cin, name);

    cout << "Введите количество товара (шт.): ";
    cin >> quantity;

    cout << "Введите дату поставки (день месяц год): ";
    cin >> day >> month >> year;

    cout << "Введите срок годности (дней): ";
    cin >> shelfLife;

    product.initializeBatch(quantity, name, day, month, year, shelfLife);
    cout << "Партия успешно создана!" << endl;
}


void showOperationsMenu(PerishableProduct& product) {
    int choice;

    do {
        cout << "\n=== МЕНЮ ОПЕРАЦИЙ ===" << endl;
        cout << "1 - Продать 1 шт. (по умолчанию)" << endl;
        cout << "2 - Продать произвольное количество" << endl;
        cout << "3 - Списать 1 шт. (по умолчанию)" << endl;
        cout << "4 - Списать произвольное количество" << endl;
        cout << "5 - Прошел 1 день" << endl;
        cout << "6 - Показать остаток" << endl;
        cout << "7 - Полный отчет" << endl;
        cout << "0 - Выход из меню операций" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            product.sellProduct();
            break;
        case 2:
        {
            int qty;
            cout << "Введите количество для продажи: ";
            cin >> qty;
            product.sellProduct(qty);
        }
        break;
        case 3:
            product.writeOffProduct();
            break;
        case 4:
        {
            int qty;
            cout << "Введите количество для списания: ";
            cin >> qty;
            product.writeOffProduct(qty);
        }
        break;
        case 5:
            product.newDay();
            break;
        case 6:
            product.displayRemaining();
            break;
        case 7:
            product.displayFullReport();
            break;
        case 0:
            cout << "Выход из меню операций" << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}

int main() {
    setlocale(LC_ALL, "rus");

    PerishableProduct product;
    int mainChoice;

    cout << "=== СИСТЕМА УЧЕТА ТОВАРНОЙ ПАРТИИ ===" << endl;

    do {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
        cout << "1 - Ввести данные партии" << endl;
        cout << "2 - Выполнить тест 1" << endl;
        cout << "3 - Выполнить тест 2" << endl;
        cout << "4 - Выполнить тест 3" << endl;
        cout << "5 - Операции с товаром" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выберите действие: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            inputProductData(product);
            break;
        case 2:
            testScenario1(product);
            break;
        case 3:
            testScenario2(product);
            break;
        case 4:
            testScenario3(product);
            break;
        case 5:
            showOperationsMenu(product);
            break;
        case 0:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (mainChoice != 0);

    return 0;
}