// ClassesPract.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
#include <string>


using namespace std;
class ServiceOrder
{
public:

    ServiceOrder(string client, string device, double diagnosticCost) : client(client), device(device), diagnosticCost(diagnosticCost) {}

    string GetClient() {
        return client;
    }

    void SetClient(string input) {
        client = input;
    }

    string GetDevice() {
        return device;
    }

    void SetDevice(string input) {
        device = input;
    }

    double GetDiagnosticCost() {
        return diagnosticCost;
    }

    void SetDiagnosticCost(double input) {
        diagnosticCost = input;
    }

    void printInfo()
    {
        cout << "Клиент: " << client << "\n" << "Устройство: " << device << "\n" << "Цена диагностики: " << diagnosticCost << endl;
    }

    void RandomizeDiagnosticCost()
    {

        int num = rand() % 3001;
    }

protected:
    std::string client{ "" };
    std::string device{ "" };
    double diagnosticCost{ 0.0 };
};

class RepairOrder : public ServiceOrder
{
public:
    using ServiceOrder::ServiceOrder;

    RepairOrder(string client, string device, double diagnosticCost, double partsCost, int workHours, double hourRate) : ServiceOrder(client,device,diagnosticCost), partsCost(partsCost), workHours(workHours), hourRate(hourRate) {}
    double GetPartsCost() {
        return partsCost;
    }

    void printInfoRepairOrder()
    {
        printInfo();

        cout << "Цена запчастей: " << partsCost << "\n" << "Часы работы: " << workHours << "\n" << "Оплата по часам: " << hourRate << "\n" << "Общая цена: " << calculateCost << "\n" << "Цена работы сотрудников: " << laborCost << "\n" << "Средняя цена часа: " << averageCostPerHour << endl;
    }

    static RepairOrder CreateRepairOrder()
    {
        cout << "Введите имя клиента:" << endl;
        try
        {
           
            string client;
            getline(cin, client);
            if (client.empty())
            {
                throw invalid_argument("Ошибка: имя клиента не может быть пустым");
            }
                
            
        
            cout << "Введите название устройства:" << endl;
        
            string device;
            getline(cin, device);
            if (device.empty())
            {
                throw invalid_argument("Ошибка: название устройства не может быть пустым");
            }
        
            cout << "Введите цену диагностики" << endl;
        
            double diagnosticCost;
            cin.ignore();
            cin >> diagnosticCost;

            if (diagnosticCost < 0)
            {
                throw invalid_argument("Ошибка: цена диагностики не может быть отрицательной");
            }
        
            cout << "Введите цену запчастей" << endl;
        
            double partsCost;
            cin.ignore();
            cin >> partsCost;

            if (partsCost < 0)
            {
                throw invalid_argument("Ошибка: цена запчастей не может быть отрицательной");
            }
        
        
            cout << "Введите часы работы" << endl;
        
            int workHours;
            cin.ignore();
            cin >> workHours;

            if (workHours <= 0)
            {
                throw invalid_argument("Ошибка: цена запчастей должна быть больше 0");
            }
        
            cout << "Введите оплату по часу" << endl;
        
            int hourRate;
            cin.ignore();
            cin >> hourRate;

            if (hourRate <= 0)
            {
                throw invalid_argument("Ошибка: оплата по часу должна быть больше 0");
            }
            RepairOrder repairOrder(client, device, diagnosticCost, partsCost, workHours, hourRate);
            return repairOrder;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << endl;
        }
        
    }

    void SetPartsCost(double input) {
        partsCost = input;
    }

    int GetWorkHours() {
        return workHours;
    }

    void SetWorkHours(int input) {
        workHours = input;
    }

    double GetHourRate() {
        return hourRate;
    }

    void SetHourRate(double input) {
        hourRate = input;
    }

    double calculateCost()
    {
        return GetDiagnosticCost() + GetPartsCost() + laborCost();
    }

    double laborCost()
    {
        return hourRate * workHours;
    }

    double averageCostPerHour()
    {
        return calculateCost() / static_cast<double>(workHours);
    }

private:
    double partsCost{ 0.0 };
    int workHours{ 0 };
    double hourRate{ 0 };
};

class MaintenanceOrder : public ServiceOrder // maintenanceOrder
{
public:
    using ServiceOrder::ServiceOrder;

    MaintenanceOrder(string client, string device, double diagnosticCost, int operations, double operationPrice, int discountPercent) : ServiceOrder(client, device, diagnosticCost), operations(operations), operationPrice(operationPrice), discountPercent(discountPercent) {}
    double GetDiscountPercent() {
        return discountPercent;
    }

    void printInfoMaintenanceOrder()
    {
        printInfo();
        

        cout << "Кол-во операций: " << operations << "\n" << "Цена одной операции: " << operationPrice << "\n" << "Скидка в процентах: " << discountPercent << "\n" << "Общая цена: " << calculateCost << "\n" << "Цена операций: " << operationsCost << "\n" << "Скидка в деньгах: " << discountAmount << endl;
        
    }

    static MaintenanceOrder CreateMaintenanceOrder()
    {
        cout << "Введите имя клиента:" << endl;
        try
        {

            string client;
            getline(cin, client);
            if (client.empty())
            {
                throw invalid_argument("Ошибка: имя клиента не может быть пустым");
            }



            cout << "Введите название устройства:" << endl;

            string device;
            getline(cin, device);
            if (device.empty())
            {
                throw invalid_argument("Ошибка: название устройства не может быть пустым");
            }

            cout << "Введите цену диагностики" << endl;

            double diagnosticCost;
            cin.ignore();
            cin >> diagnosticCost;

            if (diagnosticCost < 0)
            {
                throw invalid_argument("Ошибка: цена диагностики не может быть отрицательной");
            }

            cout << "Введите кол-во операций" << endl;

            int operations;
            cin.ignore();
            cin >> operations;

            if (operations <= 0)
            {
                throw invalid_argument("Ошибка: кол-во операций должно быть больше 0");
            }


            cout << "Введите цену одной операции" << endl;

            double operationPrice;
            cin.ignore();
            cin >> operationPrice;

            if (operationPrice <= 0)
            {
                throw invalid_argument("Ошибка: цена одной операции должна быть больше 0");
            }

            cout << "Введите процент скидки" << endl;

            int discountPercent;
            cin.ignore();
            cin >> discountPercent;

            if (discountPercent < 0 || discountPercent > 100)
            {
                throw invalid_argument("Ошибка: цена запчастей не может быть отрицательной");
            }
            MaintenanceOrder maintenanceOrder(client, device, diagnosticCost, operations, operationPrice, discountPercent);
            return maintenanceOrder;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << endl;
        }

    }

    void SetDiscountPercent(int input) {
        discountPercent = input;
    }

    int GetOperationPrice() {
        return operationPrice;
    }

    void SetOperationPrice(double input) {
        operationPrice = input;
    }

    double GetOperations() {
        return operations;
    }

    void SetOperations(int input) {
        operations = input;
    }

    double calculateCost()
    {
        return GetDiagnosticCost() + operationsCost();
    }

    double discountAmount()
    {
        return calculateCost() * static_cast<double>(discountPercent) / 100;
    }

    double operationsCost()
    {
        return operations * operationPrice;
    }

    

private:
    int operations{ 0.0 };
    double operationPrice{ 0 };
    int discountPercent{ 0 };
};

int main()
{
    srand(time(NULL));

    cout << "Введите данные о заказе на починку" << endl;

    RepairOrder repairOrder = RepairOrder::CreateRepairOrder();

    cout << "\n"  << "Введите данные о заказе на обслуживание" << endl;

    MaintenanceOrder maintenanceOrder = MaintenanceOrder::CreateMaintenanceOrder();

    cout << "\n" << "Исходное состояние заказа на починку" << endl;

    repairOrder.printInfoRepairOrder();

    cout << "\n" << "Исходное состояние заказа на обслуживание" << endl;

    maintenanceOrder.printInfoMaintenanceOrder();

    if (repairOrder.calculateCost() > maintenanceOrder.calculateCost())
    {
        cout << "\n" << "Заказ на починку дороже заказа на обслуживание" << endl;
    }
    else if (repairOrder.calculateCost() < maintenanceOrder.calculateCost())
    {
        cout << "\n" << "Заказ на починку дешевле заказа на обслуживание" << endl;
    }
    else
    {
        cout << "\n" << "Заказ на починку имеет ту же стоимость, что и заказ на обслуживание" << endl;
    }

    bool skip = false;
    do
    {
        
        cout << "\n" << "Изменение данных" << "\n" << "1 - Заказ на починку" << "\n" << "2 - Заказ на обслуживание" << "\n" << "любая другая кнопка - пропуск" << endl;
        
        int input;
        cin.ignore();
        cin >> input;

        if (input == 1) //доделать изменение данных
        {
            int inputSwitch;
            cin.ignore();
            cin >> inputSwitch;

            cout << "\n" << "Изменение данных заказа на починку" << "\n" << "1 - имя клиента" << "\n" << "2 - название устройства" << "\n" << "3 - цена диагностики" << "\n" << "4 - цена запчастей" << "\n" << "5 - рабочие часы" << "\n" << "6 - оплата по часам" << "\n" << "остальные кнопки - пропуск";
            switch (inputSwitch)
            {
            case 1:

                repairOrder.SetClient();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                break;
            }
        }
        else if (input == 2)
        {

        }
        else
        {
            skip == true;
        }
    } while (skip == false);
    

    
}