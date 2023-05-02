//Brandon Caserto
//COP 3003 - CRN 15050 - TR - 202301
//Class Project

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <random>
#include <vector>
#include <array>

class Mole {
private:
    sf::Texture moleTexture;
    sf::Sprite moleSprite;
    sf::FloatRect moleRect;
    int upTime = 0;
    sf::Sprite small_hole;
    sf::Sprite medium_hole;
    sf::Sprite large_hole;
    sf::Sprite mole_1;
    sf::Sprite mole_2;
    sf::Sprite mole_3;

public:
    Mole () {
        moleTexture.loadFromFile("mole_sheet.png");
        small_hole.setTexture(moleTexture);
        small_hole.setTextureRect(sf::IntRect(540,1130,125,85));
        medium_hole.setTexture(moleTexture);
        medium_hole.setTextureRect(sf::IntRect(280,1125,200,85));
        large_hole.setTexture(moleTexture);
        large_hole.setTextureRect(sf::IntRect(0,1110,255,85));
        mole_1.setTexture(moleTexture);
        mole_1.setTextureRect(sf::IntRect(750,800,230,125));
        mole_2.setTexture(moleTexture);
        mole_2.setTextureRect(sf::IntRect(500,800,230,125));
        mole_3.setTexture(moleTexture);
        mole_3.setTextureRect(sf::IntRect(25,700,230,210));
        moleSprite.setTexture(moleTexture);
        moleSprite.setTextureRect(sf::IntRect(225,0,225,350));
        //moleSprite.setScale(sf::Vector2f(0.20f, 0.20f));
        moleRect = small_hole.getLocalBounds();
        small_hole.setOrigin(moleRect.left + moleRect.width/2.0f, moleRect.top  + moleRect.height/2.0f);
    }
    sf::Sprite get_sprite () {
        switch(upTime) {
            case 0:
                moleSprite = small_hole;
                return moleSprite;
                break;
            case 1:
                moleSprite = medium_hole;
                return moleSprite;
                break;
            case 2:
                moleSprite = large_hole;
                return moleSprite;
                break;
            case 3 ... 4:
                moleSprite = mole_1;
                return moleSprite;
                break;
            case 5 ... 6:
                moleSprite = mole_2;
                return moleSprite;
                break;
            case 7 ... 8:
                moleSprite = mole_3;
                return moleSprite;
                break;
            case 9 ... 10:
                moleSprite = mole_2;
                return moleSprite;
                break;
            case 11 ... 12:
                moleSprite = mole_1;
                return moleSprite;
                break;
            case 13 ... 14:
                moleSprite = large_hole;
                return moleSprite;
                break;
            case 15 ... 16:
                moleSprite = medium_hole;
                return moleSprite;
                break;
            case 17 ... 18:
                moleSprite = small_hole;
                return moleSprite;
                break;
            default:
                moleSprite = small_hole;
                return moleSprite;
        }
    }
    void set_mole_rect (sf::FloatRect float_rect) {
        moleRect = float_rect;
    }
    sf::FloatRect get_mole_rect () {
        return moleRect;
    }
    void set_position (sf::Vector2f windowLocation) {
        moleSprite.setPosition(windowLocation);
    }
    void set_position_random (int window_x, int window_y) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> xGenerator((int) moleRect.width / 2, window_x - (int) moleRect.height / 2);
        int x_location = xGenerator(mt);
        std::uniform_int_distribution<int> yGenerator((int) moleRect.width / 2, window_y - (int) moleRect.height / 2);
        int y_location = yGenerator(mt);
        moleRect = small_hole.getGlobalBounds();
        small_hole.setOrigin(moleRect.left + moleRect.width/2.0f, moleRect.top  + moleRect.height/2.0f);
        small_hole.setPosition((float) x_location, (float) y_location);

        moleRect = medium_hole.getGlobalBounds();
        medium_hole.setOrigin(moleRect.left + moleRect.width/2.0f, moleRect.top  + moleRect.height/2.0f);
        medium_hole.setPosition((float) x_location, (float) y_location);

        moleRect = large_hole.getGlobalBounds();
        large_hole.setOrigin(moleRect.left + moleRect.width/2.0f, moleRect.top  + moleRect.height/2.0f);
        large_hole.setPosition((float) x_location, (float) y_location);

        moleRect = mole_1.getGlobalBounds();
        mole_1.setOrigin(moleRect.left + moleRect.width/2.0f, moleRect.top  + moleRect.height/2.0f);
        mole_1.setPosition((float) x_location, (float) y_location);

        moleRect = mole_2.getGlobalBounds();
        mole_2.setOrigin(moleRect.left + moleRect.width/2.0f, moleRect.top  + moleRect.height/2.0f);
        mole_2.setPosition((float) x_location, (float) y_location);

        moleRect = mole_3.getGlobalBounds();
        mole_3.setOrigin(moleRect.left + moleRect.width/2.0f, moleRect.top  + moleRect.height/2.0f);
        mole_3.setPosition((float) x_location, (float) y_location);
    }
    void add_uptime () {
        upTime ++;
    }
    int get_uptime () {
        return upTime;
    }
};

void main_menu ();
void game_one ();

int main() {
    while (true) {
        main_menu();
        game_one();
    }
    //creation of window
    return 0;
}

void main_menu (){
    int windowX = 1000;
    int windowY = 1000;
    sf::RenderWindow mainMenu(sf:: VideoMode(windowX, windowY), "Main Menu",
                            sf:: Style:: Close | sf:: Style:: Titlebar | sf:: Style:: Resize);
    mainMenu.setVerticalSyncEnabled(true);
    sf::View view = mainMenu.getDefaultView();
    sf::Image icon;
    icon.loadFromFile("mole_icon.png");
    mainMenu.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::Font font;
    int fontSize = 100;
    font.loadFromFile("Apple Chancery.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setString("Main Menu");
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    text.setPosition((float) mainMenu.getSize().x/2, (float) mainMenu.getSize().y/10);
    while (mainMenu.isOpen()) {
        sf::Event sfmlEvent;
        while (mainMenu.pollEvent(sfmlEvent)) {
            if(sfmlEvent.type == sfmlEvent.Closed) {
                mainMenu.close();
                exit(1);
            }
            else if (sfmlEvent.type == sf::Event::Resized) {
                // resize my view
                //view.setSize((float) (window.getSize().x), (float) (window.getSize().y));
                windowX = (int)mainMenu.getSize().x;
                std::cout << "WindowX: " << windowX << std::endl;
                std::cout << "View X: " << view.getSize().x << std::endl;
                windowY = (int)mainMenu.getSize().y;
                std::cout << "WindowY: " << windowY << std::endl;
                std::cout << "View Y: " << view.getSize().y << std::endl;
                view.reset(sf::FloatRect(0, 0, (float) windowX, (float) windowY));
            }
        }

        //creating variables for box origin and cursor location. Will potentially not need box origin but I
        //created it for testing purposes and better understanding of declaring vector values in sfml
        sf::Vector2i cursorLocation;
        sf::Vector2f realCursorLocation;
        sf::Vector2f boxOrigin;
        float xDifference = 100;
        float yDifference = 100;

        //Checking for clicking of mouse left click and getting values for box location and mouse pointer. Temporarily
        //moving mouse to pointer location as I test distance calculation
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mainMenu.hasFocus() && sf::Mouse::getPosition(mainMenu).y >= 0) {
            cursorLocation = sf::Mouse::getPosition(mainMenu);
            realCursorLocation = mainMenu.mapPixelToCoords(cursorLocation);
            mainMenu.close();
        }

        //checking to see if box and cursor location are within 5 units
        //if (xDifference <= objectX / 2 && yDifference <= objectY / 2) {

        //}

        //outputting frame
        mainMenu.clear();
        mainMenu.setView(view);
        mainMenu.draw(text);
        mainMenu.display();
    }
};

void game_one (){
    sf::Music music;
    sf::Time time;
    sf::Clock clock;
    clock.restart();
    sf::Time gameTime = clock.getElapsedTime();
    float gameSeconds = gameTime.asSeconds();
    std::cout << gameSeconds << std::endl;
    if (!music.openFromFile("game_music_1.wav"))
        std::cout << "Error\n";
    music.setLoop(true);
    music.play();
    std::vector <Mole> moleList;
    int score = 0;

    int windowX = 1000;
    int windowY = 1000;
    sf::RenderWindow window(sf:: VideoMode(windowX, windowY), "Game One",
                            sf:: Style:: Close | sf:: Style:: Titlebar | sf:: Style:: Resize);
    sf::View view = window.getDefaultView();
    window.setVerticalSyncEnabled(true);

    sf::Texture texture;
    texture.loadFromFile("grass3.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::FloatRect spriteRect = sprite.getLocalBounds();
    sprite.setOrigin(spriteRect.left + spriteRect.width/2.0f, spriteRect.top + spriteRect.height/2.0f);
    sprite.setPosition((float) window.getSize().x/2, (float) window.getSize().y/10);
    Mole temp_mole;

    sf::Font font;
    int fontSize = 50;
    font.loadFromFile("Apple Chancery.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(fontSize);
    //text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("Timer: " + std::to_string(trunc(gameSeconds)));
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    text.setPosition((float) window.getSize().x/5, (float) window.getSize().y/25);

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(fontSize);
    //scoreText.setFillColor(sf::Color::Black);
    scoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    scoreText.setString("Score: " + std::to_string(trunc(score)));
    sf::FloatRect scoreRect = scoreText.getLocalBounds();
    scoreText.setOrigin(scoreRect.left + scoreRect.width/2.0f, scoreRect.top  + scoreRect.height/2.0f);
    scoreText.setPosition((float) window.getSize().x/5, (float) window.getSize().y/10);

    //program loop to keep window open as game is being played
    gameTime = clock.getElapsedTime();
    gameSeconds = gameTime.asSeconds();
    float oldTime = gameSeconds;
    float spawnTick = 0.0;
    while (window.isOpen()) {
        sf::Event sfmlEvent;
        while (window.pollEvent(sfmlEvent)) {
            if(sfmlEvent.type == sfmlEvent.Closed) {
                window.close();
            }
            else if (sfmlEvent.type == sf::Event::Resized) {
                int changeX = (int)window.getSize().x - windowX;
                int changeY = (int)window.getSize().y - windowY;
                windowX = (int)window.getSize().x;
                windowY = (int)window.getSize().y;
                float xScale = (float) windowX / 1000;
                float yScale = (float) windowY / 1000;


                //mole_one.get_sprite().setScale(sf::Vector2f(500, moleScale * yScale));
                //mole_one.set_mole_rect(mole_one.get_sprite().getLocalBounds());
                //mole_one.get_sprite().setOrigin(mole_one.get_mole_rect().left + mole_one.get_mole_rect().width/2.0f, mole_one.get_mole_rect().top  + mole_one.get_mole_rect().height/2.0f);
                view.reset(sf::FloatRect(0, 0, (float) window.getSize().x, (float) window.getSize().y));
                sprite.setPosition((float) window.getSize().x/2, (float) window.getSize().y/2);
                //moleSprites[0].move(changeX / 2,  changeY / 2);
            }
        }

        //creating variables for box origin and cursor location. Will potentially not need box origin but I
        //created it for testing purposes and better understanding of declaring vector values in sfml
        sf::Vector2i cursorLocation;
        sf::Vector2f realCursorLocation;
        sf::Vector2f boxOrigin;
        float xDifference = 100;
        float yDifference = 100;

        //Checking for clicking of mouse left click and getting values for box location and mouse pointer. Temporarily
        //moving mouse to pointer location as I test distance calculation
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && window.hasFocus() && sf::Mouse::getPosition(window).y >= 0) {
            cursorLocation = sf::Mouse::getPosition(window);
            realCursorLocation = window.mapPixelToCoords(cursorLocation);

            for (int i = 0; i < moleList.size(); i++) {
                //window.draw(mole.get_sprite());
                moleList[i].set_mole_rect(moleList[i].get_sprite().getGlobalBounds());
                boxOrigin = moleList[i].get_sprite().getPosition();
                xDifference = abs((float) realCursorLocation.x - boxOrigin.x);
                yDifference = abs((float) realCursorLocation.y - boxOrigin.y);

                //checking to see if box and cursor location are within 5 units
                if (xDifference <= moleList[i].get_mole_rect().width / 2 && yDifference <= moleList[i].get_mole_rect().height / 2) {
                    std::random_device rd;
                    std::mt19937 mt(rd());
                    std::uniform_int_distribution<int> xGenerator((int) moleList[i].get_mole_rect().width / 2, windowX - (int) moleList[i].get_mole_rect().height / 2);
                    int x_location = xGenerator(mt);
                    std::uniform_int_distribution<int> yGenerator((int) moleList[i].get_mole_rect().width / 2, windowY - (int) moleList[i].get_mole_rect().height / 2);
                    int y_location = yGenerator(mt);
                    //moleList[i].set_position_random((int) window.getSize().x, (int) window.getSize().x);
                    moleList.erase(moleList.begin() + i);
                    score += 1;
                }
            }
        }

        gameTime = clock.getElapsedTime();
        gameSeconds = gameTime.asSeconds();

        if (gameSeconds - oldTime >= .10) {
            oldTime = gameSeconds;
            spawnTick += .10;
            for (int i = 0; i < moleList.size(); i++) {
                moleList[i].add_uptime();
            }
        }
        if (spawnTick >= 1) {
            spawnTick = 0;
            moleList.push_back(temp_mole);
            moleList[moleList.size() - 1].set_position_random((int) window.getSize().x, (int) window.getSize().y);
            moleList.push_back(temp_mole);
            moleList[moleList.size() - 1].set_position_random((int) window.getSize().x, (int) window.getSize().y);
        }

        for (int i = 0; i < moleList.size(); i++) {
            if (moleList[i].get_uptime() >= 18) {
                moleList.erase(moleList.begin() + i);
            }
        }
        //outputting frame
        if (gameSeconds <= 5) {
            window.clear();
            window.setView(view);
            window.draw(sprite);
            for (auto mole :moleList) {
                window.draw(mole.get_sprite());
            }
            text.setString("Timer: " + std::to_string(trunc(gameSeconds)));
            scoreText.setString("Score: " + std::to_string(trunc(score)));
            window.draw(text);
            window.draw(scoreText);
            window.display();
        }
        else {
            window.clear();
            sf::Text amateur;
            amateur.setFont(font);
            amateur.setCharacterSize(fontSize);
            amateur.setString("Amateur");
            sf::FloatRect amateurRect = text.getLocalBounds();
            amateur.setOrigin(amateurRect.left + amateurRect.width/2.0f, amateurRect.top  + amateurRect.height/2.0f);
            amateur.setPosition((float) window.getSize().x/2, (float) window.getSize().y/30);

            sf::Text aboveAverage;
            aboveAverage.setFont(font);
            aboveAverage.setCharacterSize(fontSize);
            aboveAverage.setString("Above Average");
            sf::FloatRect aboveAverageRect = text.getLocalBounds();
            aboveAverage.setOrigin(aboveAverageRect.left + aboveAverageRect.width/2.0f, aboveAverageRect.top  + aboveAverageRect.height/2.0f);
            aboveAverage.setPosition((float) window.getSize().x/2, (float) window.getSize().y/10);

            sf::Text professional;
            professional.setFont(font);
            professional.setCharacterSize(fontSize);
            professional.setString("Professional");
            sf::FloatRect professionalRect = text.getLocalBounds();
            professional.setOrigin(professionalRect.left + professionalRect.width/2.0f, professionalRect.top  + professionalRect.height/2.0f);
            professional.setPosition((float) window.getSize().x/2, (float) window.getSize().y/6);

            if (score / gameSeconds >= 1) {
                professional.setStyle(sf::Text::Bold | sf::Text::Underlined);
            }
            else if (score / gameSeconds >= 1.5) {
                aboveAverage.setStyle(sf::Text::Bold | sf::Text::Underlined);
            }
            else {
                amateur.setStyle(sf::Text::Bold | sf::Text::Underlined);
            }
            window.setView(view);
            window.draw(amateur);
            window.draw(aboveAverage);
            window.draw(professional);
            window.display();
        }
    }
};
