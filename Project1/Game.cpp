#include "Game.h"
#include <windows.h>

void Game::run(int n)
{
    DWORD currentTime;
    DWORD elapsedTime;
    DWORD startTime = GetTickCount64();
    DWORD lastBlockMoveTime = startTime; // Czas ostatniego ruchu klocków na dó³
    const DWORD blockMoveInterval = 20000;
    Board *board = new Board();
    Paddle paddle(board->window_size_x / 2, board->window_size_y - 50);
    Ball ball(board->window_size_x / 2, board->window_size_y - 65);
    RenderWindow window{ VideoMode{board->window_size_x,board->window_size_y}, "Arkanoid" };
    window.setFramerateLimit(board->window_size_y / 10);
    Event event;
    int blocksX = (board->window_size_x - 120) / 65;
    int blockWidth = 60, blockHeight = 20;
    int blocksY;// = 1;
    blocksY = (board->window_size_x - 120) / 120 + n; 
    vector<Block> blocks;
    for (int i = 0; i < blocksY; i++)
    {
        for (int j = 0; j < blocksX; j++)
        {
            blocks.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
        }
    }
    while (ball.get_lifeisgood())
    {
        currentTime = GetTickCount64();
        elapsedTime = currentTime - startTime;

        DWORD blockMoveElapsedTime = currentTime - lastBlockMoveTime;
        if (blockMoveElapsedTime >= blockMoveInterval)
        {
            for (auto& block : blocks)
            {
                block.moveDown(); 
            }
            lastBlockMoveTime = currentTime; 
        }
        window.clear(Color::Black);
        window.pollEvent(event);

        if (event.type == Event::Closed)
        {
            window.close();
            break;
        }
        ball.update();
        paddle.update();
        Collision kolizja;
        kolizja.collisionTest(paddle, ball);
        for (auto& block : blocks)
        {
            if (kolizja.collisionTest(block, ball)) // jezeli nie ma kolizji
            {
                break;
            }
            //algorytmy STL
            auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDistroyed(); });
            blocks.erase(iterator, end(blocks));
            if (blocks.size() == 0)
            {
                //obs³uga bledow
                try 
                {
                    int k = elapsedTime / 1000;
                    cout << "Czas gry: " << k << " sekund" << endl;
                    if (k < 1)
                    {
                        string wyjatek = "blad";
                        throw wyjatek;
                    }
                    float score = (1000 - k * 0.5 - blocks.size()) * n;
                    cout << "Score gry: " << score << " pkt" << endl;
                    if (n == 1)
                    {
                        ofstream strumien("scoreEASY.txt", ios::app);
                        strumien << score << endl;
                    }
                    if (n == 2)
                    {
                        ofstream strumien("scoreMIDDLE.txt", ios::app);
                        strumien << score << endl;
                    }
                    if (n == 3)
                    {
                        ofstream strumien("scoreHARD.txt", ios::app);
                        strumien << score << endl;
                    }
                }
                catch (string wyjatek)
                {
                    cout << wyjatek;
                }
                catch (...)
                {
                    cout << "inny blad";
                }
                RenderWindow window1{ VideoMode{board->window_size_x,board->window_size_y}, "Win" };
                win(window, window1, event);
                window1.close();
            }
            window.clear(Color::Black);
            if (block.getPosition().y >= (board->window_size_y - 150))
            {
                window.clear(Color::Red);
            }
            if (block.getPosition().y >= (board->window_size_y - 70))
            { 
                try
                {
                    int k = elapsedTime / 1000;
                    cout << "Czas gry: " << k << " sekund" << endl;
                    if (k <1)
                    {
                        string wyjatek = "blad";
                        throw wyjatek;
                    }
                    float score = (1000 - k * 0.5 - blocks.size()) * n;
                    cout << "Score gry: " << score << " pkt" << endl;
                    if (n == 1)
                    {
                        ofstream strumien("scoreEASY.txt", ios::app);
                        strumien << score << endl;
                    }
                    if (n == 2)
                    {
                        ofstream strumien("scoreMIDDLE.txt", ios::app);
                        strumien << score << endl;
                    }
                    if (n == 3)
                    {
                        ofstream strumien("scoreHARD.txt", ios::app);
                        strumien << score << endl;
                    }
                }
                catch (string wyjatek)
                {
                    cout << wyjatek;
                }
                catch (...)
                {
                    cout << "inny blad";
                }

                RenderWindow window1{ VideoMode{board->window_size_x,board->window_size_y}, "Gameover" };
                lose(window, window1, event);
            }
        }
        window.draw(ball);
        window.draw(paddle);
        for (auto& block : blocks)
        {
            window.draw(block);
        }
        window.display();
    }
    if (blocks.size() != 0)
    {
        //obs³uga b³êdów
        try
        {
            int k = elapsedTime / 1000;
            cout << "Czas gry: " << k << " sekund" << endl;
            if (k < 1)
            {
                string wyjatek = "blad";
                throw wyjatek;
            }
            float score = (1000 - k * 0.5 - blocks.size()) * n;
            cout << "Score gry: " << score << " pkt" << endl;
            if (n == 1)
            {
                ofstream strumien("scoreEASY.txt", ios::app);
                strumien << score << endl;
            }
            if (n == 2)
            {
                ofstream strumien("scoreMIDDLE.txt", ios::app);
                strumien << score << endl;
            }
            if (n == 3)
            {
                ofstream strumien("scoreHARD.txt", ios::app);
                strumien << score << endl;
            }
        }
        catch (string wyj)
        {
            cout << wyj;
           
        }
        catch (...)
        {
            cout << "inny blad";
        }
    }
    RenderWindow window1{ VideoMode{board->window_size_x,board->window_size_y}, "Gameover" };
    lose(window, window1, event);
    window1.close();
}
