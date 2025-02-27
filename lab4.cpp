//Приложение за управление на лична библиотека от цифрова медия (Media Collection Tool):  Медия това е:DVD, CD, видео.   Съдържанието на медията може да е: музика, филм , игри
#include <iostream>
#include <string>

class Item {
private:
    std::string title;
    double price;
    int mediaNumber;
    std::string mediaFormat;
    std::string purchaseDate;

public:
    Item(std::string title, double price, int mediaNumber, std::string mediaFormat, std::string purchaseDate)
        : title(title), price(price), mediaNumber(mediaNumber), mediaFormat(mediaFormat), purchaseDate(purchaseDate) {}

    std::string getTitle() const { return title; }
    double getPrice() const { return price; }
    int getMediaNumber() const { return mediaNumber; }
    std::string getMediaFormat() const { return mediaFormat; }
    std::string getPurchaseDate() const { return purchaseDate; }

    
    void displayInfo() const {
        std::cout << "<<" << getMediaType() << ">> с заглавие " << getTitle() << " е била закупена на цена " << getPrice()
                  << " на дата " << getPurchaseDate() << "." << std::endl;
    }

    
    virtual std::string getMediaType() const = 0;
};

class Movie : public Item {
private:
    int rating;

public:
    Movie(std::string title, double price, int mediaNumber, std::string mediaFormat, std::string purchaseDate, int rating)
        : Item(title, price, mediaNumber, mediaFormat, purchaseDate), rating(rating) {}

    
    std::string getMediaType() const override {
        return "Филм";
    }

    
    int getRating() const { return rating; }
};

class Game : public Item {
private:
    int difficultyLevel;

public:
    Game(std::string title, double price, int mediaNumber, std::string mediaFormat, std::string purchaseDate, int difficultyLevel)
        : Item(title, price, mediaNumber, mediaFormat, purchaseDate), difficultyLevel(difficultyLevel) {}

    
    std::string getMediaType() const override {
        return "Игра";
    }

   
    int getDifficultyLevel() const { return difficultyLevel; }
};

class Music : public Item {
private:
    std::string artist;

public:
    Music(std::string title, double price, int mediaNumber, std::string mediaFormat, std::string purchaseDate, std::string artist)
        : Item(title, price, mediaNumber, mediaFormat, purchaseDate), artist(artist) {}

    
    std::string getMediaType() const override {
        return "Музика";
    }

    
    std::string getArtist() const { return artist; }
};

int main() {
    Movie movie("Inception", 19.99, 1234, "DVD", "2023-01-15", 5);
    Game game("The Witcher 3", 39.99, 5678, "CD", "2023-02-10", 3);
    Music music("Bohemian Rhapsody", 9.99, 9101, "CD", "2023-03-20", "Queen");

    movie.displayInfo();
    std::cout << "Рейтинг: " << movie.getRating() << std::endl;

    game.displayInfo();
    std::cout << "Ниво на трудност: " << game.getDifficultyLevel() << std::endl;

    music.displayInfo();
    std::cout << "Изпълнител: " << music.getArtist() << std::endl;

    return 0;
}



