#include <iostream>
#include <string>

using namespace std;

struct stChoices
{
    string UserChoice;
    string ComputerChoice;
    string RoundWinner;
    string FinalWinner;

    short NumOfRounds;

    short UserChoiceIndex;
    short ComputerChoiceIndex;

    short UserScore = 0;
    short ComputerScore = 0;
    short DrawTimes = 0;
};
void MainMenu();
void GameLogicAndScore(stChoices& Choices);
void GetUserChoice(stChoices& Choices);
void GetComputerChoice(stChoices& Choices);
void GameRules();
void PrintRoundResults(stChoices& Choices);
void ResetValues(stChoices& Choices);
void GameOverScreen(stChoices& Choices);
void StartGame(stChoices& Choices);

void ReadNumber(string message, stChoices& Choices)
{
    cout << message << endl;
    cin >> Choices.NumOfRounds;

}

short RandomNumber(int From, int To)
{
    short randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void GameLogicAndScore(stChoices& Choices)
{
    if (Choices.UserChoiceIndex == Choices.ComputerChoiceIndex)
    {
        Choices.RoundWinner = "Draw!";
        Choices.DrawTimes++;
        system("color 6F");
    }
    else if ((Choices.UserChoiceIndex == 0) && (Choices.ComputerChoiceIndex == 2))
    {
        Choices.RoundWinner = "Player 1!";
        Choices.UserScore++;
        system("color 2F");
    }
    else if ((Choices.ComputerChoiceIndex == 0) && (Choices.UserChoiceIndex == 2))
    {
        Choices.RoundWinner = "Computer!";
        Choices.ComputerScore++;
        system("color 4F");
    }
    else if (Choices.UserChoiceIndex > Choices.ComputerChoiceIndex)
    {
        Choices.RoundWinner = "Player 1!";
        Choices.UserScore++;
        system("color 2F");
    }
    else if (Choices.ComputerChoiceIndex > Choices.UserChoiceIndex)
    {
        Choices.RoundWinner = "Computer!";
        Choices.ComputerScore++;
        system("color 4F");
    }

}

void GetUserChoice(stChoices& Choices)
{
    short UserChoice;
    cout << "\nTime to choose!\n";
    cout << "[1]: Rock\t[2]: Paper\t[3]: Scissors ? ";
    cin >> UserChoice;

    cout << endl;

    //string SelectedUserChoice;

    switch (UserChoice)
    {
    case 1:
        Choices.UserChoice = "Rock";
        Choices.UserChoiceIndex = 1;
        break;
    case 2:
        Choices.UserChoice = "Paper";
        Choices.UserChoiceIndex = 2;
        break;
    case 3:
        Choices.UserChoice = "Scissors";
        Choices.UserChoiceIndex = 3;
        break;

    default:
        break;
    }
}

void GetComputerChoice(stChoices& Choices)
{
    short choice = RandomNumber(1, 3);

    switch (choice)
    {
    case 1:
        Choices.ComputerChoice = "Rock";
        Choices.ComputerChoiceIndex = 1;
        break;
    case 2:
        Choices.ComputerChoice = "Paper";
        Choices.ComputerChoiceIndex = 2;
        break;
    case 3:
        Choices.ComputerChoice = "Scissors";
        Choices.ComputerChoiceIndex = 3;
        break;

    default:
        break;
    }
}

void GameRules()
{
    char BackToMenu;
    cout << "You will play against the Computer,\n";
    cout << "at the start of each turn, you can pick between either:\n";
    cout << "ROCK, PAPER or SCISSORS\n\n";
    cout << "PAPER beats ROCK, ROCK beats SCISSORS and SCISSORS beat PAPER!" << endl;
    cout << "Whoever wins more rounds, wins the game! Have fun! :)\n\n";

    cout << "Press M to return to main menu.\n";
    cin >> BackToMenu;
    if((BackToMenu=='M')||(BackToMenu=='m'))
        MainMenu();
}

void PrintRoundResults(stChoices& Choices)
{
    cout << "----------------------------------------------------------------------";
    cout << "\n";
    cout << "Player 1 Choice: " << Choices.UserChoice << endl;
    cout << "Computer Choice: " << Choices.ComputerChoice << endl;
    cout << "Round Winner: " << Choices.RoundWinner << endl;
    cout << " " << Choices.UserScore << "/" << Choices.ComputerScore << endl;
    cout << "----------------------------------------------------------------------";

}

void ResetValues(stChoices& Choices)
{
    Choices.UserScore = 0;
    Choices.ComputerScore = 0;
    Choices.DrawTimes = 0;
}

void GameOverScreen(stChoices& Choices)
{
    char PlayAgain;
    cout << "\n\n";
    cout << "\t\t--------------------------------------------------\n\n";
    cout << "\t\t               +++ G a m e  O v e r +++\n\n";
    cout << "\t\t--------------------------------------------------\n\n";
    cout << "\t\t-----------------  [Game Results]  ---------------\n\n";
    cout << "\t\tGame Rounds    : " << Choices.NumOfRounds << endl;
    cout << "\t\tPlayer 1 Score : " << Choices.UserScore << endl;
    cout << "\t\tComputer Score : " << Choices.ComputerScore << endl;
    cout << "\t\tDraws          : " << Choices.DrawTimes << endl;
    cout << "\t\tFinal Winner   : " << Choices.FinalWinner << endl << endl;
    cout << "\t\t--------------------------------------------------\n\n";
    cout << "\t\tDo you want to play again? Y/N ? ";
    cin >> PlayAgain;
    if ((PlayAgain == 'Y') || (PlayAgain == 'y'))
    {
        ResetValues(Choices);
        MainMenu();
    }
}

void StartGame(stChoices& Choices)
{
    ReadNumber("Enter number of rounds to play!\n", Choices);

    for (int i = 1; i <= Choices.NumOfRounds; i++)
    {
        cout << "\nRound [" << i << "]\n";

        GetUserChoice(Choices);
        GetComputerChoice(Choices);
        GameLogicAndScore(Choices);
        PrintRoundResults(Choices);
    }
    if (Choices.UserScore > Choices.ComputerScore)
        Choices.FinalWinner = "Player 1";
    else if (Choices.UserScore < Choices.ComputerScore)
        Choices.FinalWinner = "Computer";
    else
        Choices.FinalWinner = "DRAW";
    GameOverScreen(Choices);
}

void MainMenu()
{
    short MenuChoice;
    stChoices Choices;
    cout << "*****************************************************************************************************\n";
    cout << "\t\t\tWelcome to Mini-Game:Rock Paper Scissors!\n";
    cout << "*****************************************************************************************************\n\n";
    cout << "[1] : Start Game\n\n";
    cout << "[2] : Rules" << endl;
    cin >> MenuChoice;

    if (MenuChoice == 1)
        StartGame(Choices);
    else if (MenuChoice == 2)
        GameRules();
}

int main()
{
    srand((unsigned)time(NULL));
    MainMenu();
    return 0;
}

