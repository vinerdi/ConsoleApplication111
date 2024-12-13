#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Car {
    std::string name;
    int year;
    double engineVolume;
    double price;
};

class CarDealership {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void removeCar(const std::string& name) {
        cars.erase(std::remove_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.name == name;
        }), cars.end());
    }

    void displayCars() const {
        for (const auto& car : cars) {
            std::cout << "Name: " << car.name << ", Year: " << car.year
                      << ", Engine Volume: " << car.engineVolume << ", Price: " << car.price << std::endl;
        }
    }

    void sortByName() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.name < b.name;
        });
    }

    void sortByYear() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.year < b.year;
        });
    }

    void sortByEngineVolume() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.engineVolume < b.engineVolume;
        });
    }

    void sortByPrice() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.price < b.price;
        });
    }

    void searchByName(const std::string& name) const {
        auto it = std::find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.name == name;
        });
        if (it != cars.end()) {
            std::cout << "Found: " << it->name << ", Year: " << it->year
                      << ", Engine Volume: " << it->engineVolume << ", Price: " << it->price << std::endl;
        } else {
            std::cout << "Car not found." << std::endl;
        }
    }

    void searchByYear(int year) const {
        auto it = std::find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.year == year;
        });
        if (it != cars.end()) {
            std::cout << "Found: " << it->name << ", Year: " << it->year
                      << ", Engine Volume: " << it->engineVolume << ", Price: " << it->price << std::endl;
        } else {
            std::cout << "Car not found." << std::endl;
        }
    }

    void searchByEngineVolume(double engineVolume) const {
        auto it = std::find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.engineVolume == engineVolume;
        });
        if (it != cars.end()) {
            std::cout << "Found: " << it->name << ", Year: " << it->year
                      << ", Engine Volume: " << it->engineVolume << ", Price: " << it->price << std::endl;
        } else {
            std::cout << "Car not found." << std::endl;
        }
    }

    void searchByPrice(double price) const {
        auto it = std::find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.price == price;
        });
        if (it != cars.end()) {
            std::cout << "Found: " << it->name << ", Year: " << it->year
                      << ", Engine Volume: " << it->engineVolume << ", Price: " << it->price << std::endl;
        } else {
            std::cout << "Car not found." << std::endl;
        }
    }
};

int main() {
    CarDealership dealership;
    dealership.addCar({"Toyota Camry", 2020, 2.5, 24000});
    dealership.addCar({"Honda Accord", 2019, 2.0, 22000});
    dealership.addCar({"Ford Mustang", 2021, 5.0, 35000});

    std::cout << "All cars:" << std::endl;
    dealership.displayCars();

    std::cout << "\nSorted by price:" << std::endl;
    dealership.sortByPrice();
    dealership.displayCars();

    std::cout << "\nSearch by name 'Honda Accord':" << std::endl;
    dealership.searchByName("Honda Accord");

    return 0;
}
