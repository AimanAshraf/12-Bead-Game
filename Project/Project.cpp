#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>


using namespace sf;
using namespace std;

void Display(RenderWindow&);
int cointoss(RenderWindow&, Sprite, const string&, const string&);
void drawLines(RenderWindow&);
void drawBeads(CircleShape, RenderWindow&);
void game(RenderWindow&, Sprite, const string&, const string&);

const int beadRadius = 5;
const int boardRadius = 150;

String Board_image = "E:\\semester\\PF\\Assignment\\Project2\\Project2\\fspboardimage.jpg";


Texture boardTexture;
Font font;
Text title("HOPPERS GAME", font, 50);


CircleShape beads[5][5];

string playerName1;
string playerName2;

int p1beads = 12, p2beads = 12;


void initializeBeads(CircleShape beads[][5], RenderWindow& window)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i < 2)      // Red
            {

                beads[i][j].setRadius(beadRadius);
                beads[i][j].setFillColor(Color::Red);
                beads[i][j].setPosition((j * 80) + 400, (i * 80) + 150);
                beads[i][j].setOrigin(beadRadius, beadRadius);

            }
            else if (i == 2)
            {

                if (j < 2)
                {
                    beads[i][j].setRadius(beadRadius);
                    beads[i][j].setFillColor(Color::Red);
                    beads[i][j].setPosition((j * 80) + 400, (i * 80) + 150);
                    beads[i][j].setOrigin(beadRadius, beadRadius);
                }
                else if (j == 2)
                {
                    beads[i][j].setRadius(beadRadius);
                    beads[i][j].setFillColor(Color::Transparent);
                    beads[i][j].setPosition((j * 80) + 400, (i * 80) + 150);
                    beads[i][j].setOrigin(beadRadius, beadRadius);
                }
                else
                {
                    beads[i][j].setRadius(beadRadius);
                    beads[i][j].setFillColor(Color::Green);
                    beads[i][j].setPosition((j * 80) + 400, (i * 80) + 150);
                    beads[i][j].setOrigin(beadRadius, beadRadius);
                }

            }
            else
            {

                beads[i][j].setRadius(beadRadius);
                beads[i][j].setFillColor(Color::Green);
                beads[i][j].setPosition((j * 80) + 400, (i * 80) + 150);
                beads[i][j].setOrigin(beadRadius, beadRadius);

            }

        }
    }

}

void drawLines(RenderWindow& window)
{

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            float startX = (i * 80) + 400;
            float startY = (j * 80) + 150;

            // Squares

            if (i > 0) {
                float endX = ((i - 1) * 80) + 400;
                float endY = (j * 80) + 150;
                Vertex line[] = {
                    Vertex(Vector2f(startX, startY), Color::Black),
                    Vertex(Vector2f(endX, endY), Color::Black)
                };
                window.draw(line, 2, Lines);
            }
            if (j > 0) {
                float endX = (i * 80) + 400;
                float endY = ((j - 1) * 80) + 150;
                Vertex line[] = {
                    Vertex(Vector2f(startX, startY), Color::Black),
                    Vertex(Vector2f(endX, endY), Color::Black)
                };
                window.draw(line, 2, Lines);
            }

            // Right Diagonals 

            if (i == j && j != 4)
            {
                float endX = ((i + 1) * 80) + 400;
                float endY = ((j + 1) * 80) + 150;
                Vertex line[] = {
                    Vertex(Vector2f(startX, startY), Color::Black),
                    Vertex(Vector2f(endX, endY), Color::Black)
                };
                window.draw(line, 2, Lines);
            }

            if (i == (j - 2) && j != 4)
            {
                float endX = ((i + 1) * 80) + 400;
                float endY = ((j + 1) * 80) + 150;
                Vertex line[] = {
                    Vertex(Vector2f(startX, startY), Color::Black),
                    Vertex(Vector2f(endX, endY), Color::Black)
                };
                window.draw(line, 2, Lines);
            }

            if (i == (j + 2) && i != 4)
            {
                float endX = ((i + 1) * 80) + 400;
                float endY = ((j + 1) * 80) + 150;
                Vertex line[] = {
                    Vertex(Vector2f(startX, startY), Color::Black),
                    Vertex(Vector2f(endX, endY), Color::Black)
                };
                window.draw(line, 2, Lines);
            }

            // Left Diagonals

            if (i + j == 4 && i != 4)
            {
                float endX = ((i + 1) * 80) + 400;
                float endY = ((j - 1) * 80) + 150;
                Vertex line[] = {
                    Vertex(Vector2f(startX, startY), Color::Black),
                    Vertex(Vector2f(endX, endY), Color::Black)
                };
                window.draw(line, 2, Lines);
            }

            if (i + j == 2 && i < 2)
            {
                float endX = ((i + 1) * 80) + 400;
                float endY = ((j - 1) * 80) + 150;
                Vertex line[] = {
                    Vertex(Vector2f(startX, startY), Color::Black),
                    Vertex(Vector2f(endX, endY), Color::Black)
                };
                window.draw(line, 2, Lines);
            }

            if (i + j == 6 && i < 4)
            {
                float endX = ((i + 1) * 80) + 400;
                float endY = ((j - 1) * 80) + 150;
                Vertex line[] = {
                    Vertex(Vector2f(startX, startY), Color::Black),
                    Vertex(Vector2f(endX, endY), Color::Black)
                };
                window.draw(line, 2, Lines);
            }


        }
    }

}

void drawBeads(CircleShape beads[][5], RenderWindow& window)
{
    Text upperarray[5];
    Text lowerarray[5];

    char ch = 'A';

    for (int a = 0; a < 5; a++)
    {
        upperarray[a].setString(ch);
        upperarray[a].setFont(font);
        upperarray[a].setCharacterSize(20);
        upperarray[a].setPosition((a * 80) + 400, 110);
        ch++;

        lowerarray[a].setString(to_string(a + 1));
        lowerarray[a].setFont(font);
        lowerarray[a].setCharacterSize(20);
        lowerarray[a].setPosition(370, (a * 80) + 135);
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; j++)
        {
            window.draw(beads[j][i]);
            window.draw(upperarray[j]);
            window.draw(lowerarray[j]);
        }
    }
}

void Instruction_Menu(RenderWindow& window, Sprite boardSprite)
{

    Text Instruction("Instructions,", font, 40);
    Instruction.setPosition(80, 200);

    Text Option("1. Each Player Has 12 Beads \n2. Players Take Turns \n3. You Can Only Move on Path Given\n4. Capture Enemies All Beads To Win", font, 30);
    Option.setPosition(80, 270);


    Text ret_menu("Press Space To Go Back To Menu !", font, 30);
    ret_menu.setPosition(80, 500);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {
                window.close();
            }


            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Space)
                {
                    Display(window);
                }
                else
                {
                    window.close();
                }
            }


        }



        window.clear();
        // Draw Background

        Sprite boardSprite(boardTexture);
        boardSprite.setScale(400, 150);

        window.draw(boardSprite);

        // Draw elements for coin toss
        window.draw(title);
        window.draw(Instruction);
        window.draw(Option);
        window.draw(ret_menu);


        window.display();
    }

}

int cointoss(RenderWindow& window, Sprite boardSprite, const string& playerName1, const string& playerName2)
{
    Text CoinToss("Choose Heads or Tails,", font, 40);
    CoinToss.setPosition(80, 200.f);

    Text Option("1. Heads \t 2. Tails", font, 30);
    Option.setPosition(80, 270.f);

    Text Start_Game("Click To Play !", font, 40);
    Start_Game.setPosition(80, 450);

    int toss = -1; // Initialize toss to an invalid value

    srand(time(NULL));
    int coin = -1;
    coin = rand() % 2;

    bool check = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                // Get mouse position in pixel coordinates
                Vector2i mousePosition = Mouse::getPosition(window);

                // Check if the mouse click is within the bounding box of Heads or Tails options
                if (Option.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {
                    if (!check)
                    {
                        // Check which option is clicked
                        if (mousePosition.x < 240)          // 240 cuz of X position of Heads
                        {
                            toss = 0; // Heads
                        }
                        else
                        {
                            toss = 1; // Tails
                        }
                        check = true;
                    }
                }
                else if (Start_Game.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {
                    cout << "Starting Game ... ";

                    if (toss == coin)
                    {
                        game(window, boardSprite, playerName1, playerName2);
                    }
                    else
                    {
                        game(window, boardSprite, playerName2, playerName1);
                    }
                    window.close();
                }
                else
                {
                    window.close();
                }
            }
        }

        window.clear();

        // Draw Background
        boardSprite.setScale(400, 150);
        window.draw(boardSprite);

        drawLines(window);
        drawBeads(beads, window);

        // Draw elements for coin toss
        window.draw(title);
        window.draw(CoinToss);
        window.draw(Option);

        Text res;
        res.setFont(font);
        res.setCharacterSize(40);
        res.setPosition(80, 340);

        if (check == 0)
        {
            res.setString("It's Heads!");
        }
        else
        {
            res.setString("It's Tails!");
        }

        if (check)
        {
            Text resultText;
            resultText.setFont(font);
            resultText.setCharacterSize(40);
            resultText.setPosition(80, 390);

            if (toss == 0)
            {
                resultText.setString(playerName1 + " chose Heads!");
                window.draw(resultText);
                window.draw(res);
            }
            else if (toss == 1)
            {
                resultText.setString(playerName1 + " chose Tails!");
                window.draw(resultText);
                window.draw(res);
            }

            window.draw(Start_Game);
        }

        window.display();
    }

    if (toss == coin)
    {
        return 1;       // player one won the toss
    }
    else
    {
        return 0;       // player one lost the toss
    }
}

string getPlayerName(RenderWindow& window, Sprite boardSprite)
{
    string playerName = "";

    Text enterNameText("Enter Player Name:", font, 30);
    enterNameText.setPosition(80, 200);

    Text playerNameText("", font, 30);
    playerNameText.setPosition(80, 270);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::TextEntered)
            {
                if (event.text.unicode > 66 && event.text.unicode < 128)        // Takes input in ascii and check if ascii greater than numbers and less than special characters
                {
                    playerName += event.text.unicode;
                    playerNameText.setString(playerName);
                }
            }

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Enter && !playerName.empty())
                {
                    return playerName;
                }
            }
        }

        window.clear();

        // Draw Background
        boardSprite.setScale(400, 150);
        window.draw(boardSprite);
        drawLines(window);
        drawBeads(beads, window);

        // Draw elements for coin toss
        window.draw(title);

        // Draw elements for entering player name
        window.draw(enterNameText);
        window.draw(playerNameText);

        window.display();
    }

    return ""; // Return empty string if the window is closed before entering a name
}

void getPlayerPos(RenderWindow& window, Sprite boardSprite, const string& playerName1, const string& playerName2, int arr[])
{
    Text p1(playerName1 + " - " + to_string(p1beads), font, 30);

    Text p2(playerName2 + " - " + to_string(p2beads), font, 30);

    p1.setFillColor(Color::Red);
    p1.setPosition(400, 60);

    p2.setFillColor(Color::Green);
    p2.setPosition(600, 60);

    string BeadPosition;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                Vector2i mousePosition = Mouse::getPosition(window);    // Mouse Position

                // Check if any bead is clicked
                for (int i = 0; i < 5; ++i)
                {
                    for (int j = 0; j < 5; ++j)
                    {
                        if (beads[i][j].getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                        {
                            arr[0] = i;
                            arr[1] = j;
                            return;

                        }
                    }
                }
            }

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Enter && !BeadPosition.empty())
                {

                }
            }
        }

        window.clear();


        // Draw Background

        Sprite boardSprite(boardTexture);
        boardSprite.setScale(400, 150);
        window.draw(boardSprite);

        drawLines(window);
        drawBeads(beads, window);

        // Draw elements for coin toss
        window.draw(title);
        window.draw(p1);
        window.draw(p2);




        window.display();
    }

}

void Display(RenderWindow& window)
{
    boardTexture.loadFromFile(Board_image);

    Sprite boardSprite(boardTexture);
    boardSprite.setScale(400, 150);

    font.loadFromFile("SunnyspellsRegular-MV9ze.otf");

    title.setPosition(80, 50);

    Text startText("1. Start Game", font, 30);
    startText.setPosition(80, 200.f);

    Text instructionsText("2. Instructions", font, 30);
    instructionsText.setPosition(80, 250.f);

    Text exitText("3. Exit", font, 30);
    exitText.setPosition(80, 300.f);

    initializeBeads(beads, window);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                // Get mouse position in pixel coordinates
                Vector2i mousePosition = Mouse::getPosition(window);

                // Check if any menu option is clicked
                if (startText.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {

                    // Get Players Names
                    string playerName1 = getPlayerName(window, boardSprite);
                    string playerName2 = getPlayerName(window, boardSprite);

                    // Move Text Outside Board
                    startText.setPosition(900, 900);
                    instructionsText.setPosition(900, 900);
                    exitText.setPosition(900, 900);

                    std::cout << "Hello " << playerName1 << endl;
                    std::cout << "Hello " << playerName2 << endl;

                    // Get Toss Value (1 = Player one Won Toss & 0 means Player one Lost Toss)
                    int choice = cointoss(window, boardSprite, playerName1, playerName2);

                    window.close();
                }
                else if (instructionsText.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {

                    startText.setPosition(900, 900);
                    instructionsText.setPosition(900, 900);
                    exitText.setPosition(900, 900);

                    Instruction_Menu(window, boardSprite);

                    window.close();
                }
                else if (exitText.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                {
                    window.close();
                }
            }
        }

        window.clear();

        // Draw Board
        window.draw(boardSprite);
        drawLines(window);
        drawBeads(beads, window);

        // Draw the menu text on top of the background
        window.draw(title);
        window.draw(startText);
        window.draw(instructionsText);
        window.draw(exitText);

        window.display();
    }
}

bool bead_Check()
{
    if (p1beads < 1 || p2beads < 1)
        return true;
    else
        return false;
}
bool implementation(int old_arr[], int new_arr[], Color  d1, Color d2, int& check, int& bead)
{//main logic(conditions)

    if (old_arr[0] == 0 && old_arr[1] == 0)
    {
        if (new_arr[0] == 0 && new_arr[1] == 1 && beads[0][1].getFillColor() == Color::Transparent)
            beads[0][1].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][1].getFillColor() == Color::Transparent)
            beads[1][1].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 0 && beads[1][0].getFillColor() == Color::Transparent)
            beads[1][0].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 2 && beads[0][1].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent)
        {
            beads[0][2].setFillColor(d1);
            beads[0][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[1][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent)
        {
            beads[2][2].setFillColor(d1);
            beads[1][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[1][0].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent)
        {
            beads[2][0].setFillColor(d1);
            beads[1][0].setFillColor(d2);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[0][0].setFillColor(Color::Transparent);
        return true;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 1)
    {
        if (new_arr[0] == 0 && new_arr[1] == 0 && beads[0][0].getFillColor() == Color::Transparent)
            beads[0][0].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 2 && beads[0][2].getFillColor() == Color::Transparent)
            beads[0][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][1].getFillColor() == Color::Transparent)
            beads[1][1].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 3 && beads[0][2].getFillColor() == d2 && beads[0][3].getFillColor() == Color::Transparent)
        {
            beads[0][3].setFillColor(d1);
            beads[0][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 1 && beads[1][1].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent)
        {
            beads[2][1].setFillColor(d1);
            beads[1][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[0][1].setFillColor(Color::Transparent);
        return true;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 2)
    {
        if (new_arr[0] == 0 && new_arr[1] == 1 && beads[0][1].getFillColor() == Color::Transparent)
            beads[0][1].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 3 && beads[0][3].getFillColor() == Color::Transparent)
            beads[0][3].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][1].getFillColor() == Color::Transparent)
            beads[1][1].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 2 && beads[1][2].getFillColor() == Color::Transparent)
            beads[1][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][3].getFillColor() == Color::Transparent)
            beads[1][3].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 0 && beads[0][1].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent)
        {
            beads[0][0].setFillColor(d1);
            beads[0][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 0 && new_arr[1] == 4 && beads[0][3].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent)
        {
            beads[0][4].setFillColor(d1);
            beads[0][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[1][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent)
        {
            beads[2][0].setFillColor(d1);
            beads[1][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[1][2].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent)
        {
            beads[2][2].setFillColor(d1);
            beads[1][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[1][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent)
        {
            beads[2][4].setFillColor(d1);
            beads[1][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[0][2].setFillColor(Color::Transparent);
        return true;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 3)
    {
        if (new_arr[0] == 0 && new_arr[1] == 2 && beads[0][2].getFillColor() == Color::Transparent)
            beads[0][2].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 4 && beads[0][4].getFillColor() == Color::Transparent)
            beads[0][4].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][3].getFillColor() == Color::Transparent)
            beads[1][3].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 1 && beads[0][2].getFillColor() == d2 && beads[0][1].getFillColor() == Color::Transparent)
        {
            beads[0][1].setFillColor(d1);
            beads[0][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 3 && beads[1][3].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent)
        {
            beads[2][3].setFillColor(d1);
            beads[1][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[0][3].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 0 && old_arr[1] == 4)
    {
        if (new_arr[0] == 0 && new_arr[1] == 3 && beads[0][3].getFillColor() == Color::Transparent)
            beads[0][3].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][3].getFillColor() == Color::Transparent)
            beads[1][3].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 4 && beads[1][4].getFillColor() == Color::Transparent)
            beads[1][4].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 2 && beads[0][3].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent)
        {
            beads[0][2].setFillColor(d1);
            beads[0][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[1][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent)
        {
            beads[2][2].setFillColor(d1);
            beads[1][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[1][4].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent)
        {
            beads[2][4].setFillColor(d1);
            beads[1][4].setFillColor(d2);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[0][4].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 1 && old_arr[1] == 0)
    {
        if (new_arr[0] == 0 && new_arr[1] == 0 && beads[0][0].getFillColor() == Color::Transparent)
            beads[0][0].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[2][0].getFillColor() == Color::Transparent)
            beads[2][0].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][1].getFillColor() == Color::Transparent)
            beads[1][1].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 2 && beads[1][1].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent)
        {
            beads[1][2].setFillColor(d1);
            beads[1][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 0 && beads[2][0].getFillColor() == d2 && beads[3][0].getFillColor() == Color::Transparent)
        {
            beads[3][0].setFillColor(d1);
            beads[2][0].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[1][0].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 1 && old_arr[1] == 1)
    {
        if (new_arr[0] == 0 && new_arr[1] == 0 && beads[0][0].getFillColor() == Color::Transparent)
            beads[0][0].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 0 && beads[1][0].getFillColor() == Color::Transparent)
            beads[1][0].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[2][0].getFillColor() == Color::Transparent)
            beads[2][0].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 1 && beads[0][1].getFillColor() == Color::Transparent)
            beads[0][1].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 1 && beads[2][1].getFillColor() == Color::Transparent)
            beads[2][1].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 2 && beads[0][2].getFillColor() == Color::Transparent)
            beads[0][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 2 && beads[1][2].getFillColor() == Color::Transparent)
            beads[1][2].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][2].getFillColor() == Color::Transparent)
            beads[2][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][2].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent)
        {
            beads[1][3].setFillColor(d1);
            beads[1][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[2][1].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent)
        {
            beads[3][1].setFillColor(d1);
            beads[2][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[2][2].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent)
        {
            beads[3][3].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[1][1].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 1 && old_arr[1] == 2)
    {
        if (new_arr[0] == 0 && new_arr[1] == 2 && beads[0][2].getFillColor() == Color::Transparent)
            beads[0][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][1].getFillColor() == Color::Transparent)
            beads[1][1].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][2].getFillColor() == Color::Transparent)
            beads[2][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][3].getFillColor() == Color::Transparent)
            beads[1][3].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 0 && beads[1][1].getFillColor() == d2 && beads[1][0].getFillColor() == Color::Transparent)
        {
            beads[1][0].setFillColor(d1);
            beads[1][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 2 && beads[2][2].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent)
        {
            beads[3][2].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 1 && new_arr[1] == 4 && beads[1][3].getFillColor() == d2 && beads[1][4].getFillColor() == Color::Transparent)
        {
            beads[1][4].setFillColor(d1);
            beads[1][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[1][2].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 1 && old_arr[1] == 3)
    {
        if (new_arr[0] == 0 && new_arr[1] == 4 && beads[0][4].getFillColor() == Color::Transparent)
            beads[0][4].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 4 && beads[1][4].getFillColor() == Color::Transparent)
            beads[1][4].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[2][4].getFillColor() == Color::Transparent)
            beads[2][4].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 3 && beads[0][3].getFillColor() == Color::Transparent)
            beads[0][3].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 3 && beads[2][3].getFillColor() == Color::Transparent)
            beads[2][3].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 2 && beads[0][2].getFillColor() == Color::Transparent)
            beads[0][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 2 && beads[1][2].getFillColor() == Color::Transparent)
            beads[1][2].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][2].getFillColor() == Color::Transparent)
            beads[2][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][2].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent)
        {
            beads[1][1].setFillColor(d1);
            beads[1][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[2][2].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent)
        {
            beads[3][1].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[2][3].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent)
        {
            beads[3][3].setFillColor(d1);
            beads[2][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[1][3].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 1 && old_arr[1] == 4)
    {
        if (new_arr[0] == 0 && new_arr[1] == 4 && beads[0][4].getFillColor() == Color::Transparent)
            beads[0][4].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[2][4].getFillColor() == Color::Transparent)
            beads[2][4].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][3].getFillColor() == Color::Transparent)
            beads[1][3].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 2 && beads[1][3].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent)
        {
            beads[1][2].setFillColor(d1);
            beads[1][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 4 && beads[2][4].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent)
        {
            beads[3][4].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[1][4].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 2 && old_arr[1] == 0)
    {
        if (new_arr[0] == 1 && new_arr[1] == 0 && beads[1][0].getFillColor() == Color::Transparent)
            beads[1][0].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 0 && beads[3][0].getFillColor() == Color::Transparent)
            beads[3][0].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][1].getFillColor() == Color::Transparent)
            beads[1][1].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 1 && beads[2][1].getFillColor() == Color::Transparent)
            beads[2][1].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][1].getFillColor() == Color::Transparent)
            beads[3][1].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 0 && beads[1][0].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent)
        {
            beads[0][0].setFillColor(d1);
            beads[1][0].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 0 && beads[3][0].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent)
        {
            beads[4][0].setFillColor(d1);
            beads[3][0].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 0 && new_arr[1] == 2 && beads[1][1].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent)
        {
            beads[0][2].setFillColor(d1);
            beads[1][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent)
        {
            beads[2][2].setFillColor(d1);
            beads[2][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 2 && beads[3][1].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent)
        {
            beads[4][2].setFillColor(d1);
            beads[3][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[2][0].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 2 && old_arr[1] == 1)
    {
        if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][1].getFillColor() == Color::Transparent)
            beads[1][1].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[2][0].getFillColor() == Color::Transparent)
            beads[2][0].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][1].getFillColor() == Color::Transparent)
            beads[3][1].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][2].getFillColor() == Color::Transparent)
            beads[2][2].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 1 && beads[1][1].getFillColor() == d2 && beads[0][1].getFillColor() == Color::Transparent)
        {
            beads[0][1].setFillColor(d1);
            beads[1][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 3 && beads[2][2].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent)
        {
            beads[2][3].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 1 && beads[3][1].getFillColor() == d2 && beads[4][1].getFillColor() == Color::Transparent)
        {
            beads[4][1].setFillColor(d1);
            beads[3][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[2][1].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 2 && old_arr[1] == 2)
    {
        if (new_arr[0] == 1 && new_arr[1] == 1 && beads[1][1].getFillColor() == Color::Transparent)
            beads[1][1].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 1 && beads[2][1].getFillColor() == Color::Transparent)
            beads[2][1].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][1].getFillColor() == Color::Transparent)
            beads[3][1].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 2 && beads[1][2].getFillColor() == Color::Transparent)
            beads[1][2].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 2 && beads[3][2].getFillColor() == Color::Transparent)
            beads[3][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][3].getFillColor() == Color::Transparent)
            beads[1][3].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 3 && beads[2][3].getFillColor() == Color::Transparent)
            beads[2][3].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][3].getFillColor() == Color::Transparent)
            beads[3][3].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 0 && beads[1][1].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent)
        {
            beads[0][0].setFillColor(d1);
            beads[1][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 0 && new_arr[1] == 2 && beads[1][2].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent)
        {
            beads[1][2].setFillColor(d1);
            beads[0][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 0 && new_arr[1] == 4 && beads[1][3].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent)
        {
            beads[0][4].setFillColor(d1);
            beads[1][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[2][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent)
        {
            beads[2][0].setFillColor(d1);
            beads[2][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[2][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent)
        {
            beads[2][4].setFillColor(d1);
            beads[2][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 0 && beads[3][1].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent)
        {
            beads[4][0].setFillColor(d1);
            beads[3][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 2 && beads[3][2].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent)
        {
            beads[4][2].setFillColor(d1);
            beads[3][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 4 && beads[3][3].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent)
        {
            beads[4][4].setFillColor(d1);
            beads[3][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[2][2].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 2 && old_arr[1] == 3)
    {
        if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][3].getFillColor() == Color::Transparent)
            beads[1][3].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[2][4].getFillColor() == Color::Transparent)
            beads[2][4].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][3].getFillColor() == Color::Transparent)
            beads[3][3].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][2].getFillColor() == Color::Transparent)
            beads[2][2].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 3 && beads[1][3].getFillColor() == d2 && beads[0][3].getFillColor() == Color::Transparent)
        {
            beads[0][3].setFillColor(d1);
            beads[1][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 1 && beads[2][2].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent)
        {
            beads[2][1].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 3 && beads[3][3].getFillColor() == d2 && beads[4][3].getFillColor() == Color::Transparent)
        {
            beads[4][3].setFillColor(d1);
            beads[3][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[2][3].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 2 && old_arr[1] == 4)
    {
        if (new_arr[0] == 1 && new_arr[1] == 4 && beads[1][4].getFillColor() == Color::Transparent)
            beads[1][4].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 4 && beads[3][4].getFillColor() == Color::Transparent)
            beads[3][4].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[1][3].getFillColor() == Color::Transparent)
            beads[1][3].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 3 && beads[2][3].getFillColor() == Color::Transparent)
            beads[2][3].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][3].getFillColor() == Color::Transparent)
            beads[3][3].setFillColor(d1);
        else if (new_arr[0] == 0 && new_arr[1] == 4 && beads[1][4].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent)
        {
            beads[0][4].setFillColor(d1);
            beads[1][4].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 4 && beads[3][4].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent)
        {
            beads[4][4].setFillColor(d1);
            beads[3][4].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 0 && new_arr[1] == 2 && beads[1][3].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent)
        {
            beads[0][2].setFillColor(d1);
            beads[1][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent)
        {
            beads[2][2].setFillColor(d1);
            beads[2][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 2 && beads[3][3].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent)
        {
            beads[4][2].setFillColor(d1);
            beads[3][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[2][4].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 3 && old_arr[1] == 0)
    {
        if (new_arr[0] == 4 && new_arr[1] == 0 && beads[4][0].getFillColor() == Color::Transparent)
            beads[4][0].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[2][0].getFillColor() == Color::Transparent)
            beads[2][0].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][1].getFillColor() == Color::Transparent)
            beads[3][1].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 2 && beads[3][1].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent)
        {
            beads[3][2].setFillColor(d1);
            beads[3][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 1 && new_arr[1] == 0 && beads[2][0].getFillColor() == d2 && beads[1][0].getFillColor() == Color::Transparent)
        {
            beads[1][0].setFillColor(d1);
            beads[2][0].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[3][0].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 3 && old_arr[1] == 1)
    {
        if (new_arr[0] == 4 && new_arr[1] == 0 && beads[4][0].getFillColor() == Color::Transparent)
            beads[4][0].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 0 && beads[3][0].getFillColor() == Color::Transparent)
            beads[3][0].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[2][0].getFillColor() == Color::Transparent)
            beads[2][0].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 1 && beads[4][1].getFillColor() == Color::Transparent)
            beads[4][1].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 1 && beads[2][1].getFillColor() == Color::Transparent)
            beads[2][1].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 2 && beads[4][2].getFillColor() == Color::Transparent)
            beads[4][2].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 2 && beads[3][2].getFillColor() == Color::Transparent)
            beads[3][2].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][2].getFillColor() == Color::Transparent)
            beads[2][2].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][2].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent)
        {
            beads[3][3].setFillColor(d1);
            beads[3][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[2][1].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent)
        {
            beads[1][1].setFillColor(d1);
            beads[2][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[2][2].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent)
        {
            beads[1][3].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[3][1].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 3 && old_arr[1] == 2)
    {
        if (new_arr[0] == 4 && new_arr[1] == 2 && beads[4][2].getFillColor() == Color::Transparent)
            beads[4][2].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][1].getFillColor() == Color::Transparent)
            beads[3][1].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][2].getFillColor() == Color::Transparent)
            beads[2][2].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][3].getFillColor() == Color::Transparent)
            beads[3][3].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 0 && beads[3][1].getFillColor() == d2 && beads[3][0].getFillColor() == Color::Transparent)
        {
            beads[3][0].setFillColor(d1);
            beads[3][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 1 && new_arr[1] == 2 && beads[2][2].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent)
        {
            beads[1][2].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 4 && beads[3][3].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent)
        {
            beads[3][4].setFillColor(d1);
            beads[3][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[3][2].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 3 && old_arr[1] == 3)
    {
        if (new_arr[0] == 4 && new_arr[1] == 4 && beads[4][4].getFillColor() == Color::Transparent)
            beads[4][4].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 4 && beads[3][4].getFillColor() == Color::Transparent)
            beads[3][4].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[2][4].getFillColor() == Color::Transparent)
            beads[2][4].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 3 && beads[4][3].getFillColor() == Color::Transparent)
            beads[4][3].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 3 && beads[2][3].getFillColor() == Color::Transparent)
            beads[2][3].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 2 && beads[4][2].getFillColor() == Color::Transparent)
            beads[4][2].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 2 && beads[3][2].getFillColor() == Color::Transparent)
            beads[3][2].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[2][2].getFillColor() == Color::Transparent)
            beads[2][2].setFillColor(d1);
        else if (new_arr[0] == 1 && new_arr[1] == 1 && beads[2][2].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent)
        {
            beads[1][1].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][2].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent)
        {
            beads[3][1].setFillColor(d1);
            beads[3][2].setFillColor(Color::Transparent);
            check = 1;

        }
        else if (new_arr[0] == 1 && new_arr[1] == 3 && beads[2][3].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent)
        {
            beads[1][3].setFillColor(d1);
            beads[2][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[3][3].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 3 && old_arr[1] == 4)
    {
        if (new_arr[0] == 4 && new_arr[1] == 4 && beads[4][4].getFillColor() == Color::Transparent)
            beads[4][4].setFillColor(d1);
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[2][4].getFillColor() == Color::Transparent)
            beads[2][4].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][3].getFillColor() == Color::Transparent)
            beads[3][3].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 2 && beads[3][3].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent)
        {
            beads[3][2].setFillColor(d1);
            beads[3][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 1 && new_arr[1] == 4 && beads[2][4].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent)
        {
            beads[3][4].setFillColor(d1);
            beads[2][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[3][4].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 4 && old_arr[1] == 0)
    {
        if (new_arr[0] == 4 && new_arr[1] == 1 && beads[4][1].getFillColor() == Color::Transparent)
            beads[4][1].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][1].getFillColor() == Color::Transparent)
            beads[3][1].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 0 && beads[3][0].getFillColor() == Color::Transparent)
            beads[3][0].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 2 && beads[4][1].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent)
        {
            beads[4][2].setFillColor(d1);
            beads[4][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[3][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent)
        {
            beads[2][2].setFillColor(d1);
            beads[3][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[3][0].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent)
        {
            beads[2][0].setFillColor(d1);
            beads[3][0].setFillColor(d2);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[4][0].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 4 && old_arr[1] == 1)
    {
        if (new_arr[0] == 4 && new_arr[1] == 0 && beads[4][0].getFillColor() == Color::Transparent)
            beads[4][0].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 2 && beads[4][2].getFillColor() == Color::Transparent)
            beads[4][2].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][1].getFillColor() == Color::Transparent)
            beads[3][1].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 3 && beads[4][2].getFillColor() == d2 && beads[4][3].getFillColor() == Color::Transparent)
        {
            beads[4][3].setFillColor(d1);
            beads[4][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 1 && beads[3][1].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent)
        {
            beads[2][1].setFillColor(d1);
            beads[3][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[4][1].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 4 && old_arr[1] == 2)
    {
        if (new_arr[0] == 4 && new_arr[1] == 1 && beads[4][1].getFillColor() == Color::Transparent)
            beads[4][1].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 3 && beads[4][3].getFillColor() == Color::Transparent)
            beads[4][3].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 1 && beads[3][1].getFillColor() == Color::Transparent)
            beads[3][1].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 2 && beads[3][2].getFillColor() == Color::Transparent)
            beads[3][2].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][3].getFillColor() == Color::Transparent)
            beads[3][3].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 0 && beads[4][1].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent)
        {
            beads[4][0].setFillColor(d1);
            beads[4][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 4 && new_arr[1] == 4 && beads[4][3].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent)
        {
            beads[4][4].setFillColor(d1);
            beads[4][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 0 && beads[3][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent)
        {
            beads[2][0].setFillColor(d1);
            beads[3][1].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[3][2].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent)
        {
            beads[2][2].setFillColor(d1);
            beads[3][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[3][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent)
        {
            beads[2][4].setFillColor(d1);
            beads[3][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[4][2].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 4 && old_arr[1] == 3)
    {
        if (new_arr[0] == 4 && new_arr[1] == 2 && beads[4][2].getFillColor() == Color::Transparent)
            beads[4][2].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 4 && beads[4][4].getFillColor() == Color::Transparent)
            beads[4][4].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][3].getFillColor() == Color::Transparent)
            beads[3][3].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 1 && beads[4][2].getFillColor() == d2 && beads[4][1].getFillColor() == Color::Transparent)
        {
            beads[4][1].setFillColor(d1);
            beads[4][2].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 3 && beads[3][3].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent)
        {
            beads[2][3].setFillColor(d1);
            beads[3][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[4][3].setFillColor(Color::Transparent);
        return true;
        }
    else if (old_arr[0] == 4 && old_arr[1] == 4)
    {
        if (new_arr[0] == 4 && new_arr[1] == 3 && beads[4][3].getFillColor() == Color::Transparent)
            beads[4][3].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 3 && beads[3][3].getFillColor() == Color::Transparent)
            beads[3][3].setFillColor(d1);
        else if (new_arr[0] == 3 && new_arr[1] == 4 && beads[3][4].getFillColor() == Color::Transparent)
            beads[3][4].setFillColor(d1);
        else if (new_arr[0] == 4 && new_arr[1] == 2 && beads[4][3].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent)
        {
            beads[4][2].setFillColor(d1);
            beads[4][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 2 && beads[3][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent)
        {
            beads[2][2].setFillColor(d1);
            beads[3][3].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else if (new_arr[0] == 2 && new_arr[1] == 4 && beads[3][4].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent)
        {
            beads[2][4].setFillColor(d1);
            beads[3][4].setFillColor(Color::Transparent);
            check = 1;
            bead--;
        }
        else
            return false;
        beads[4][4].setFillColor(Color::Transparent);
        return true;
        }
    else
        return false;
}
bool movecp1(int old_arr[])
{
    if ((old_arr[0]<5 && old_arr[0] > -1) || (old_arr[1]<5 && old_arr[1] > -1))
        return true;
    else
        return false;

}


bool movecp2(int old_arr[], Color d1)
{
    if ((old_arr[0] == 0 && old_arr[1] == 0 && beads[0][0].getFillColor() == d1) || (old_arr[0] == 1 && old_arr[1] == 0 && beads[1][0].getFillColor() == d1) || (old_arr[0] == 2 && old_arr[1] == 0 && beads[2][0].getFillColor() == d1) || (old_arr[0] == 3 && old_arr[1] == 0 && beads[3][0].getFillColor() == d1) || (old_arr[0] == 4 && old_arr[1] == 0 && beads[4][0].getFillColor() == d1) || (old_arr[0] == 0 && old_arr[1] == 1 && beads[0][1].getFillColor() == d1) || (old_arr[0] == 1 && old_arr[1] == 1 && beads[1][1].getFillColor() == d1) || (old_arr[0] == 2 && old_arr[1] == 1 && beads[2][1].getFillColor() == d1) || (old_arr[0] == 3 && old_arr[1] == 1 && beads[3][1].getFillColor() == d1) || (old_arr[0] == 4 && old_arr[1] == 1 && beads[4][1].getFillColor() == d1) || (old_arr[0] == 0 && old_arr[1] == 2 && beads[0][2].getFillColor() == d1) || (old_arr[0] == 1 && old_arr[1] == 2 && beads[1][2].getFillColor() == d1) || (old_arr[0] == 2 && old_arr[1] == 2 && beads[2][2].getFillColor() == d1) || (old_arr[0] == 3 && old_arr[1] == 2 && beads[3][2].getFillColor() == d1) || (old_arr[0] == 4 && old_arr[1] == 2 && beads[4][2].getFillColor() == d1) || (old_arr[0] == 0 && old_arr[1] == 3 && beads[0][3].getFillColor() == d1) || (old_arr[0] == 1 && old_arr[1] == 3 && beads[1][3].getFillColor() == d1) || (old_arr[0] == 2 && old_arr[1] == 3 && beads[2][3].getFillColor() == d1) || (old_arr[0] == 3 && old_arr[1] == 3 && beads[3][3].getFillColor() == d1) || (old_arr[0] == 4 && old_arr[1] == 3 && beads[4][3].getFillColor() == d1) || (old_arr[0] == 0 && old_arr[1] == 4 && beads[0][4].getFillColor() == d1) || (old_arr[0] == 1 && old_arr[1] == 4 && beads[1][4].getFillColor() == d1) || (old_arr[0] == 2 && old_arr[1] == 4 && beads[2][4].getFillColor() == d1) || (old_arr[0] == 3 && old_arr[1] == 4 && beads[3][4].getFillColor() == d1) || (old_arr[0] == 4 && old_arr[1] == 4 && beads[4][4].getFillColor() == d1))
        return true;
    else
        return false;
}


bool movecp3(int old_arr[], Color d1, Color d2)
{
    if (old_arr[0] == 0 && old_arr[1] == 0)
    {
        if (beads[0][1].getFillColor() == Color::Transparent || beads[1][1].getFillColor() == Color::Transparent || beads[1][0].getFillColor() == Color::Transparent || (beads[0][1].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[1][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[1][0].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent))
            return true;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 1)
    {
        if (beads[0][0].getFillColor() == Color::Transparent || beads[0][2].getFillColor() == Color::Transparent || beads[1][1].getFillColor() == Color::Transparent || (beads[0][2].getFillColor() == d2 && beads[0][3].getFillColor() == Color::Transparent) || (beads[1][1].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent))
            return true;

    }
    else if (old_arr[0] == 0 && old_arr[1] == 2)
    {
        if (beads[0][1].getFillColor() == Color::Transparent || beads[0][3].getFillColor() == Color::Transparent || beads[1][1].getFillColor() == Color::Transparent || beads[1][2].getFillColor() == Color::Transparent || beads[1][3].getFillColor() == Color::Transparent || (beads[0][1].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent) || (beads[0][3].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent) || (beads[1][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent) || (beads[1][2].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent))
            return true;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 3)
    {
        if (beads[0][2].getFillColor() == Color::Transparent || beads[0][4].getFillColor() == Color::Transparent || beads[1][3].getFillColor() == Color::Transparent || (beads[0][2].getFillColor() == d2 && beads[0][1].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 4)
    {
        if (beads[0][3].getFillColor() == Color::Transparent || beads[1][3].getFillColor() == Color::Transparent || beads[1][4].getFillColor() == Color::Transparent || (beads[0][3].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[1][4].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent))
            return true;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 0)
    {
        if (beads[0][0].getFillColor() == Color::Transparent || beads[2][0].getFillColor() == Color::Transparent || beads[1][1].getFillColor() == Color::Transparent || (beads[1][1].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent) || (beads[2][0].getFillColor() == d2 && beads[3][0].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 1)
    {
        if (beads[0][0].getFillColor() == Color::Transparent || beads[1][0].getFillColor() == Color::Transparent || beads[2][0].getFillColor() == Color::Transparent || beads[0][1].getFillColor() == Color::Transparent || beads[2][1].getFillColor() == Color::Transparent || beads[0][2].getFillColor() == Color::Transparent || beads[1][2].getFillColor() == Color::Transparent || beads[2][2].getFillColor() == Color::Transparent || (beads[1][2].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent) || (beads[2][1].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent))
            return true;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 2)
    {
        if (beads[0][2].getFillColor() == Color::Transparent || beads[1][1].getFillColor() == Color::Transparent || beads[2][2].getFillColor() == Color::Transparent || beads[1][3].getFillColor() == Color::Transparent || (beads[1][1].getFillColor() == d2 && beads[1][0].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[1][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 3)
    {
        if (beads[0][4].getFillColor() == Color::Transparent || beads[1][4].getFillColor() == Color::Transparent || beads[2][4].getFillColor() == Color::Transparent || beads[0][3].getFillColor() == Color::Transparent || beads[2][3].getFillColor() == Color::Transparent || beads[0][2].getFillColor() == Color::Transparent || beads[1][2].getFillColor() == Color::Transparent || beads[2][2].getFillColor() == Color::Transparent || (beads[1][2].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent) || (beads[2][3].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 4)
    {
        if (beads[0][4].getFillColor() == Color::Transparent || beads[2][4].getFillColor() == Color::Transparent || beads[1][3].getFillColor() == Color::Transparent || (beads[1][3].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent) || (beads[2][4].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 0)
    {
        if (beads[1][0].getFillColor() == Color::Transparent || beads[3][0].getFillColor() == Color::Transparent || beads[1][1].getFillColor() == Color::Transparent || beads[2][1].getFillColor() == Color::Transparent || beads[3][1].getFillColor() == Color::Transparent || (beads[1][0].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent) || (beads[3][0].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent) || (beads[1][1].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[2][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 1)
    {
        if (beads[1][1].getFillColor() == Color::Transparent || beads[2][0].getFillColor() == Color::Transparent || beads[3][1].getFillColor() == Color::Transparent || beads[2][2].getFillColor() == Color::Transparent || (beads[1][1].getFillColor() == d2 && beads[0][1].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[4][1].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 2)
    {
        if (beads[1][1].getFillColor() == Color::Transparent || beads[2][1].getFillColor() == Color::Transparent || beads[3][1].getFillColor() == Color::Transparent || beads[1][2].getFillColor() == Color::Transparent || beads[3][2].getFillColor() == Color::Transparent || beads[1][3].getFillColor() == Color::Transparent || beads[2][3].getFillColor() == Color::Transparent || beads[3][3].getFillColor() == Color::Transparent || (beads[1][1].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent) || (beads[1][2].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent) || (beads[2][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent) || (beads[2][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent) || (beads[3][2].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 3)
    {
        if (beads[1][3].getFillColor() == Color::Transparent || beads[2][4].getFillColor() == Color::Transparent || beads[3][3].getFillColor() == Color::Transparent || beads[2][2].getFillColor() == Color::Transparent || (beads[1][3].getFillColor() == d2 && beads[0][3].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[4][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 4)
    {
        if (beads[1][4].getFillColor() == Color::Transparent || beads[3][4].getFillColor() == Color::Transparent || beads[1][3].getFillColor() == Color::Transparent || beads[2][3].getFillColor() == Color::Transparent || beads[3][3].getFillColor() == Color::Transparent || (beads[1][4].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent) || (beads[3][4].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[2][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 0)
    {
        if (beads[4][0].getFillColor() == Color::Transparent || beads[2][0].getFillColor() == Color::Transparent || beads[3][1].getFillColor() == Color::Transparent || (beads[3][1].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent) || (beads[2][0].getFillColor() == d2 && beads[1][0].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 1)
    {
        if (beads[4][0].getFillColor() == Color::Transparent || beads[3][0].getFillColor() == Color::Transparent || beads[2][0].getFillColor() == Color::Transparent || beads[4][1].getFillColor() == Color::Transparent || beads[2][1].getFillColor() == Color::Transparent || beads[4][2].getFillColor() == Color::Transparent || beads[3][2].getFillColor() == Color::Transparent || beads[2][2].getFillColor() == Color::Transparent || (beads[3][2].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent) || (beads[2][1].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 2)
    {
        if (beads[4][2].getFillColor() == Color::Transparent || beads[3][1].getFillColor() == Color::Transparent || beads[2][2].getFillColor() == Color::Transparent || beads[3][3].getFillColor() == Color::Transparent || (beads[3][1].getFillColor() == d2 && beads[3][0].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 3)
    {
        if (beads[4][4].getFillColor() == Color::Transparent || beads[3][4].getFillColor() == Color::Transparent || beads[2][4].getFillColor() == Color::Transparent || beads[4][3].getFillColor() == Color::Transparent || beads[2][3].getFillColor() == Color::Transparent || beads[4][2].getFillColor() == Color::Transparent || beads[3][2].getFillColor() == Color::Transparent || beads[2][2].getFillColor() == Color::Transparent || (beads[2][2].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent) || (beads[3][2].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent) || (beads[2][3].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 4)
    {
        if (beads[4][4].getFillColor() == Color::Transparent || beads[2][4].getFillColor() == Color::Transparent || beads[3][3].getFillColor() == Color::Transparent || (beads[3][3].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent) || (beads[2][4].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 0)
    {
        if (beads[4][1].getFillColor() == Color::Transparent || beads[3][1].getFillColor() == Color::Transparent || beads[3][0].getFillColor() == Color::Transparent || (beads[4][1].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][0].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 1)
    {
        if (beads[4][0].getFillColor() == Color::Transparent || beads[4][2].getFillColor() == Color::Transparent || beads[3][1].getFillColor() == Color::Transparent || (beads[4][2].getFillColor() == d2 && beads[4][3].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 2)
    {
        if (beads[4][1].getFillColor() == Color::Transparent || beads[4][3].getFillColor() == Color::Transparent || beads[3][1].getFillColor() == Color::Transparent || beads[3][2].getFillColor() == Color::Transparent || beads[3][3].getFillColor() == Color::Transparent || (beads[4][1].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent) || (beads[4][3].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent) || (beads[3][2].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 3)
    {
        if (beads[4][2].getFillColor() == Color::Transparent || beads[4][4].getFillColor() == Color::Transparent || beads[3][3].getFillColor() == Color::Transparent || (beads[4][2].getFillColor() == d2 && beads[4][1].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 4)
    {
        if (beads[4][3].getFillColor() == Color::Transparent || beads[3][3].getFillColor() == Color::Transparent || beads[3][4].getFillColor() == Color::Transparent || (beads[4][3].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][4].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else
        return false;

}

bool movenp(int old_arr[], Color d1, Color d2)
{// to check k agaye tu koi bead nhi mar rha if yes tu ye chance de rha 
    if (old_arr[0] == 0 && old_arr[1] == 0)
    {
        if ((beads[0][1].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[1][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[1][0].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 1)
    {
        if ((beads[0][2].getFillColor() == d2 && beads[0][3].getFillColor() == Color::Transparent) || (beads[1][1].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 2)
    {
        if ((beads[0][1].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent) || (beads[0][3].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent) || (beads[1][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent) || (beads[1][2].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 3)
    {
        if ((beads[0][2].getFillColor() == d2 && beads[0][1].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 0 && old_arr[1] == 4)
    {
        if ((beads[0][3].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[1][4].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 0)
    {
        if ((beads[1][1].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent) || (beads[2][0].getFillColor() == d2 && beads[3][0].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 1)
    {
        if ((beads[1][2].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent) || (beads[2][1].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 2)
    {
        if ((beads[1][1].getFillColor() == d2 && beads[1][0].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[1][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 3)
    {
        if ((beads[1][2].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent) || (beads[2][3].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 1 && old_arr[1] == 4)
    {
        if ((beads[1][3].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent) || (beads[2][4].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 0)
    {
        if ((beads[1][0].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent) || (beads[3][0].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent) || (beads[1][1].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[2][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 1)
    {
        if ((beads[1][1].getFillColor() == d2 && beads[0][1].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[4][1].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 2)
    {
        if ((beads[1][1].getFillColor() == d2 && beads[0][0].getFillColor() == Color::Transparent) || (beads[1][2].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent) || (beads[2][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent) || (beads[2][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent) || (beads[3][2].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 3)
    {
        if ((beads[1][3].getFillColor() == d2 && beads[0][3].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[4][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 2 && old_arr[1] == 4)
    {
        if ((beads[1][4].getFillColor() == d2 && beads[0][4].getFillColor() == Color::Transparent) || (beads[3][4].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent) || (beads[1][3].getFillColor() == d2 && beads[0][2].getFillColor() == Color::Transparent) || (beads[2][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 0)
    {
        if ((beads[3][1].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent) || (beads[2][0].getFillColor() == d2 && beads[1][0].getFillColor() == Color::Transparent))
            return 0;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 1)
    {
        if ((beads[3][2].getFillColor() == d2 && beads[3][3].getFillColor() == Color::Transparent) || (beads[2][1].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 2)
    {
        if ((beads[3][1].getFillColor() == d2 && beads[3][0].getFillColor() == Color::Transparent) || (beads[2][2].getFillColor() == d2 && beads[1][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 3)
    {
        if ((beads[2][2].getFillColor() == d2 && beads[1][1].getFillColor() == Color::Transparent) || (beads[3][2].getFillColor() == d2 && beads[3][1].getFillColor() == Color::Transparent) || (beads[2][3].getFillColor() == d2 && beads[1][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 3 && old_arr[1] == 4)
    {
        if ((beads[3][3].getFillColor() == d2 && beads[3][2].getFillColor() == Color::Transparent) || (beads[2][4].getFillColor() == d2 && beads[3][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 0)
    {
        if ((beads[4][1].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][0].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 1)
    {
        if ((beads[4][2].getFillColor() == d2 && beads[4][3].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[2][1].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 2)
    {
        if ((beads[4][1].getFillColor() == d2 && beads[4][0].getFillColor() == Color::Transparent) || (beads[4][3].getFillColor() == d2 && beads[4][4].getFillColor() == Color::Transparent) || (beads[3][1].getFillColor() == d2 && beads[2][0].getFillColor() == Color::Transparent) || (beads[3][2].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 3)
    {
        if ((beads[4][2].getFillColor() == d2 && beads[4][1].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[2][3].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else if (old_arr[0] == 4 && old_arr[1] == 4)
    {
        if ((beads[4][3].getFillColor() == d2 && beads[4][2].getFillColor() == Color::Transparent) || (beads[3][3].getFillColor() == d2 && beads[2][2].getFillColor() == Color::Transparent) || (beads[3][4].getFillColor() == d2 && beads[2][4].getFillColor() == Color::Transparent))
            return true;
        else
            return false;
    }
    else
        return false;
}
void turnn(int turn, Color& d1, Color& d2, string& PlayerName, const string& playerName1, const string& playerName2, int& bead)
{//to decide the bead
    if (turn % 2 == 0)
    {
        d1 = Color::Red;
        d2 = Color::Green;
        PlayerName = playerName1;
        bead = p2beads;
    }
    else
    {
        d2 = Color::Red;
        d1 = Color::Green;
        PlayerName = playerName2;
        bead = p1beads;
    }
}
void winner(Color d1, string playerName1, string  playerName2)
{
    if (d1 == Color::Red)
        cout << endl << playerName1 << " is the winner";
    else
        cout << endl << playerName2 << " is the winner";
}
void game(RenderWindow& window, Sprite boardSprite, const string& playerName1, const string& playerName2)
{
    int check = 0, turn = 3, checkcp1 = 0, checkcp2 = 0, checkcp3 = 0, checknp1 = 0, checknp2 = 0, bead = 12;
    Color d1 = Color::Red;
    Color d2 = Color::Green;
    string PlayerName = "";
    Text p1(playerName1 + " - " + to_string(p1beads), font, 30);
    Text p2(playerName2 + " - " + to_string(p2beads), font, 30);

    p1.setFillColor(Color::Red);
    p1.setPosition(400, 60);

    p2.setFillColor(Color::Green);
    p2.setPosition(600, 60);

    int BeadPos[2] = {};
    int NewBeadPos[2] = {};




    while (bead_Check() == false)
    {
        checkcp1 = 0;
        checkcp2 = 0;
        checkcp3 = 0;
        checknp1 = 0;
        checknp2 = 0;
        window.clear();
        // Draw Background
        if (d1 == Color::Red)
            p2beads = bead;
        else
            p1beads = bead;
        if (bead_Check() == true)
            break;
        Sprite boardSprite(boardTexture);
        boardSprite.setScale(400, 150);
        window.draw(boardSprite);

        drawLines(window);
        drawBeads(beads, window);

        // Draw elements for coin toss
        window.draw(title);
        window.draw(p1);
        window.draw(p2);

        if (check == 1)
        {
            checknp2 = movenp(NewBeadPos, d1, d2);
            check = 0;
        }
        if (checknp2 == 0)
        {
            turn++;
            turnn(turn, d1, d2, PlayerName, playerName1, playerName2, bead);
            while (checkcp1 == 0 || checkcp2 == 0 || checkcp3 == 0)
            {
                BeadPos[0] = 0;
                BeadPos[1] = 0;
                getPlayerPos(window, boardSprite, playerName1, playerName2, BeadPos);
                cout << "\n " << PlayerName << " Old Bead Position : " << BeadPos[0] << " " << BeadPos[1] << endl;
                checkcp1 = movecp1(BeadPos);
                checkcp2 = movecp2(BeadPos, d1);
                checkcp3 = movecp3(BeadPos, d1, d2);
                cout << checkcp1 << checkcp2 << checkcp3;

            }
        }
        else
        {
            BeadPos[0] = NewBeadPos[0];
            BeadPos[1] = NewBeadPos[1];
        }
        while (checknp1 == 0)
        {
            NewBeadPos[0] = 0;
            NewBeadPos[1] = 0;
            getPlayerPos(window, boardSprite, playerName1, playerName2, NewBeadPos);
            cout << "\n " << PlayerName << " New Bead Position : " << NewBeadPos[0] << " " << NewBeadPos[1] << endl;

            checknp1 = implementation(BeadPos, NewBeadPos, d1, d2, check, bead);
            cout << checknp1;
        }

        window.display();

    }
    winner(d1, playerName1, playerName2);
}


int main()
{
    RenderWindow window(VideoMode(800, 600), "HOPPERS");

    Display(window);

    return 0;
}