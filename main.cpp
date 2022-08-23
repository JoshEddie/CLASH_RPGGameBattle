//Include ranger header which links to all other needed includes.
//Necessary files: Ranger(.hpp/.cpp), Wizard(.hpp/.cpp), Knight(.hpp/.cpp), functions(.hpp/.cpp).
#include "Ranger.hpp"

//Used for creating a new character.
void createCharacter(string classType, vector<Character*> &players, string playerName) {
    
    if(classType == "Wizard") {
        Wizard *wizardptr =  new Wizard(playerName);
        players.push_back(wizardptr);
    }
    else if(classType == "Ranger") {
        Ranger *rangerptr =  new Ranger(playerName);
        players.push_back(rangerptr);
    }
    else {
        Knight *knightptr =  new Knight(playerName);
        players.push_back(knightptr);
    }
    
}
//Used for loading a saved character.
void createCharacter(string classType, vector<Character*> &players, string playerName, Player player) {
    
    if(classType == "Wizard") {
        Wizard *wizardptr = new Wizard(playerName, player);
        players.push_back(wizardptr);
    }
    else if(classType == "Ranger") {
        Ranger *rangerptr = new Ranger(playerName, player);
        players.push_back(rangerptr);
    }
    else {
        Knight *knightptr = new Knight(playerName, player);
        players.push_back(knightptr);
    }
    
}

//Used for checking if playerName exists and if so what index is it at in the vector.
int findPlayerIndex(vector<Character*> *players, string playerName) {
    
    int index = -1; //if no result is found the index will return as -1 which tells the program nothing was found.

    for(int i = 0; i < players->size(); ++i) {
        //if(playerName.find(players->at(i)->getName()) != string::npos) {
        if(playerName == players->at(i)->getName()) {
            index = i;
            break;
        }
    }
    
    return index;
    
}

//Prompts user to choose between available classes.
int chooseClass(string textBoxTitle, vector<Character*> &players, string &playerName, string &classType) {
    
    string choice ="n";
    string pressEnter = "press enter to continue";
    
    Wizard *wizardExample =  new Wizard(playerName);
    Knight *knightExample =  new Knight(playerName);
    Ranger *rangerExample =  new Ranger(playerName);
    
    textBox(textBoxTitle, "A new champion! I'll get you setup at once, ", "but first I need to find out what type of fighter you are.", pressEnter);
    cin.get();
    
    //Choose Player Class Loop
    do {
        
        //textBox(textBoxTitle, "What weapon speaks to you?.", "", "");
        
        //ACII Art for Weapon Choice
        cout << right << " " << setfill('-') << setw(80) << " " << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << textBoxTitle + ": " << "|" << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << "What weapon speaks to you?" << "|" << endl;
        cout << "|                                                                               |" << endl;
        cout << "|    ____                                                            /\\         |" << endl;
        cout << "|   |    \\                                                          (  )        |" << endl;
        cout << "|   |     \\                       _______/\\______                    )(         |" << endl;
        cout << "|   |      \\                      |             |                    /\\         |" << endl;
        cout << "|   |       \\                     |             |                    )(         |" << endl;
        cout << "|   |\\\\\\     \\                    |      |      |                   (  )        |" << endl;
        cout << "|   |--------------->             |     —|—     |                   |  |        |" << endl;
        cout << "|   |///     /                    |      |      |                   )  (        |" << endl;
        cout << "|   |       /                     |             |                  (    )       |" << endl;
        cout << "|   |      /                      \\             /                   \\  /        |" << endl;
        cout << "|   |     /                        \\___________/                    | |         |" << endl;
        cout << "|   |    /                                                          | |         |" << endl;
        cout << "|   |___/                                                           |_|         |" << endl;
        cout << "|                                                                               |" << endl;
        //End of ACII Art for weapons
        
        cout << "|  [b] Bow                          [s] Shield                   [w] Wand       |" << endl;
        cout << "|                                                                               |" << endl;
        cout << "|                                                  [press key [s], [b], or [w]  |" << endl;
        cout << right << " " << setfill('-') << setw(80) << " " << endl;
        cin >> choice;
        cin.ignore();
        cout << endl;
        
        if(choice == "s") {
            knightExample->printCharacter();
            textBox(textBoxTitle, "You desire to protect? Defending others as a KNIGHT.", "", "press key y / n");
            classType = "Knight";
        }
        else if (choice == "b") {
            rangerExample->printCharacter();
            textBox(textBoxTitle, "You desire to be quick? Using your wits as a RANGER.", "", "press key y / n");
            classType = "Ranger";
        }
        else if (choice == "w") {
            wizardExample->printCharacter();
            textBox(textBoxTitle, "You desire power? Wielding the magic of a WIZARD.", "", "press key y / n");
            classType = "Wizard";
        }
        else {
            textBox(textBoxTitle, "I don't understand", "", "");
            continue;
        }
        cin >> choice;
        cin.ignore();
        cout << endl;
        
    } while(choice != "y");
    
    createCharacter(classType, players, playerName);
    int player1Index = static_cast<unsigned int>(players.size() - 1);
    
    delete wizardExample;
    delete knightExample;
    delete rangerExample;
    
    return player1Index;
    
}

//Code to manage asking user for a name and whether to load or create a new character.
int loadCreatePlayer(string textBoxTitle, vector<Character*> &players, string &playerName, string &classType) {
    
    string choice;
    string pressEnter = "press enter to continue";
    int player1Index;
    
    do {
        
        textBox(textBoxTitle, "What is your name?", "", "type name or \"forgot\" to see list");
        getline(cin, playerName);
        cout << endl;
        
        //Will print a list of saved characters
        while(playerName == "forgot") {
            
            textBox(textBoxTitle, "WHAT! You forgot???", "Well I think I have a list around here somewhere. . .", pressEnter);
            cin.get();
            
            cout << right << " " << setfill('-') << setw(80) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|";
            cout << left << setfill(' ') << setw(77) << "FIGHTERS:" << "|" << endl;
            for(int i = 0; i < players.size(); ++i) {
                cout << left << setfill(' ') << setw(3) << "|";
                cout << left << setfill(' ') << setw(77) << "[" + to_string(i + 1) + "] -- " + players.at(i)->getName() + " | Level " + to_string(players.at(i)->getLevel()) + " " + players.at(i)->getClassType() << "|" << endl;
                pauseMilliseconds(200);
            }
            
            cout << right << " " << setfill('-') << setw(80) << " " << endl;
            pauseMilliseconds(200);
            
            textBox(textBoxTitle, "Well, do you recognize yourself?", "", "enter # or n");
            cin >> choice;
            cin.ignore();
            cout << endl;
            
            if(choice != "n") {
                if(isnumber(choice[0]) && stoi(choice) > 0 && stoi(choice) <= players.size()) {
                    playerName = players.at(stoi(choice) - 1)->getName();
                }
                else {
                    textBox(textBoxTitle, "I don't recognize that.", "", "press enter to continue");
                    continue;
                }
            }
            else {
                textBox(textBoxTitle, "Too bad, but we will have to call you something", "", "type name or \"forgot\" to see list again");
                getline(cin, playerName);
                cout << endl;
            }
            
        }
        
        player1Index = findPlayerIndex(&players, playerName);
        
        if(player1Index >= 0) {
            
            players.at(player1Index)->printCharacter();

            textBox(textBoxTitle, "You are " + players.at(player1Index)->getName() + "?", "", "press key y / n");
            cin >> choice;
            cin.ignore();
            cout << endl;
            
        }
        else {
            
            textBox(textBoxTitle, "Your name is " + playerName, "", "press key y / n");
            cin >> choice;
            cin.ignore();
            cout << endl;
            
        }
        
        
    } while (choice != "y");
    
    if(player1Index < 0) {
        player1Index = chooseClass(textBoxTitle, players, playerName, classType);
    }
    
    return player1Index;
    
}

//Function that allows a user to change the name of their character and checks if the new name isn't already taken.
void changeName(string textBoxTitle, Character &player, vector<Character*> players) {
    
    string choice, playerName;
    
    do {
        
        textBox(textBoxTitle, "You would like to change your name?", "", "press key y / n");
        cin >> choice;
        cin.ignore();
        cout << endl;
        
        if(choice == "n") {
            break;
        }
        
        textBox(textBoxTitle, "What would you like your new name to be?", "", "enter name");
        getline(cin, playerName);
        cout << endl;
        
        int player1Index = findPlayerIndex(&players, playerName);
        
        while(player1Index >= 0) {
            textBox(textBoxTitle, "Somebody already has that name.", "Is there another name you would like to be called?", "enter name");
            getline(cin, playerName);
            cout << endl;
            
            player1Index = findPlayerIndex(&players, playerName);
            
        }
        
        player.setName(playerName);
        //player1Index = findPlayerIndex(&players, playerName);
        textBox(textBoxTitle, "We will now call you " + player.getName() + ".", "", "press enter to continue");
        cin.get();
        
    } while (choice != "y");
    
}

int main() {

    string choice = "1"; //Used to store most player input and logic checks in the program.
    string playerName, classType;
    Player loadPlayer; //Structure used to load in data from a file and send into constructor.
    vector<Character*> players; //List of users created players.
    vector<Character*> opponents; //Populated with randomly generated opponents as a player continues to fight the computer.
    int player1Index = -1, player2Index = -1;
    int numDefeated = 0, highScore = 0;
    int highScoreIndex = -1;
    
    srand(static_cast<unsigned int>(time(0))); //Seeds random with the current time.
    
    //Strings of commonly repeated text used throughout the program.
    string innKeeperTitle = "Inn Keeper";
    string trainerTitle = "Instructor Dan";
    string tournamentMaster = "Tournament Master";
    string pressEnter = "press enter to continue";
    
    //Creates a character used in the training program to test actions against.
    Knight *trainingCharacter = new Knight(trainerTitle);
    
    //Checks if saved players file exists and if so loads character information from it and saves it into the players vector.
    ifstream fin("players.txt");
    if(fin.is_open()) {
        
        getline(fin, playerName);
        
        while(playerName.find("High Score") == string::npos) {
            getline(fin, classType);
            fin >> loadPlayer.hp;
            fin >> loadPlayer.attack;
            fin >> loadPlayer.defense;
            fin >> loadPlayer.speed;
            fin >> loadPlayer.evasion;
            fin >> loadPlayer.level;
            fin >> loadPlayer.exp;
            fin >> loadPlayer.act1Lvl;
            fin >> loadPlayer.act2Lvl;
            fin >> loadPlayer.act3Lvl;
            fin >> loadPlayer.act4Lvl;
            fin.ignore();
            fin.ignore();
            createCharacter(classType, players, playerName, loadPlayer);
            getline(fin, playerName);
        }
        fin >> highScore;
        fin >> highScoreIndex;
        
    }
    fin.close();
    //End of loading from a file.
    
    //Prints opening title, CLASH, to the console with it slowly rising from the bottom to simulate an animated graphic.
    for(int i= 0; i < 100; i++) {
        cout << endl;
    }
    pauseMilliseconds(400); //Call to function in functions.cpp to sleep program for number of Milliseconds sent in.
    cout << "             ______     __         ______     ______     __  __" << endl;
    pauseMilliseconds(400);
    cout << "            /\\  ___\\   /\\ \\       /\\  __ \\   /\\  ___\\   /\\ \\_\\ \\" << endl;
    pauseMilliseconds(400);
    cout << "            \\ \\ \\____  \\ \\ \\____  \\ \\  __ \\  \\ \\___  \\  \\ \\  __ \\ "<< endl;
    pauseMilliseconds(400);
    cout << "             \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\/\\_____\\  \\ \\_\\ \\_\\" << endl;
    pauseMilliseconds(400);
    cout << "              \\/_____/   \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/\\/_/" << endl;
    pauseMilliseconds(400);
    cout << endl;
    pauseMilliseconds(400);
    cout << endl;
    pauseMilliseconds(400);
    //End of opening title sequence.

    textBox(innKeeperTitle, "Welcome young traveler to the Blue Dragon Inn and the CLASH of Champions!", "", pressEnter); //Call to function in functions.cpp that controls textbox formatting.
    cin.get();
    
    //Get name, load character if exists, confirms character name/character to load
    player1Index = loadCreatePlayer(innKeeperTitle, players, playerName, classType);
    
    //Check if player level is 1 and recommend training (tutorial).
    while(players.at(player1Index)->getLevel() == 1) {
        
        textBox(innKeeperTitle, "You might be a little weak for the tournament.", "Would you like to train some?", "press key y / n");
        cin >> choice;
        cin.ignore();
        cout << endl;
        
        //Send player to training if they answer yes
        if(choice == "y") {
            players.at(player1Index)->training(trainerTitle, *trainingCharacter);
            break;
        }
        else if(choice == "n") {
            break;
        }
        
    }
    //End training recommendation
    
    //Checks if current player has the high score.
    if(player1Index == highScoreIndex) {
        textBox(tournamentMaster, "Master " + players.at(player1Index)->getName() + ", you here to teach these losers a lesson?", "", pressEnter);
        cin.get();
    }
    //Checks player level and give a response based on level.
    else if(players.at(player1Index)->getLevel() >= 5) {
        textBox(tournamentMaster, "Huh, it's " + players.at(player1Index)->getName() + ". You might impress me yet.", "", pressEnter);
        cin.get();
    }
    else if(players.at(player1Index)->getLevel() > 2) {
        textBox(tournamentMaster, "Well, you got lucky it seems. You should quit while you are ahead.", "", pressEnter);
        cin.get();
    }
    else {
        textBox(tournamentMaster, "This way is for fighters only.", "The stands are that way.", pressEnter);
        cin.get();
        textBox(tournamentMaster, "Huh, you are here to fight?", "Well, I won't be the one cleaning up your body.", pressEnter);
        cin.get();
    }
    //End level check and response.
    
    //Main Game loop
    do {
        
        printMenu();
        cin >> choice;
        cin.ignore();
        cout << endl;
        
        if(choice == "1") {
            
            do {
                
                string botName = nameGenerator();
                int classRand = rand() % 3;
                
                if(classRand == 0) {
                    classType = "Knight";
                }
                else if (classRand == 1) {
                    classType = "Wizard";
                }
                else {
                    classType = "Ranger";
                }
                
                createCharacter(classType, opponents, botName);
                
                player2Index = static_cast<unsigned int>(opponents.size() - 1);
                
                for(int i = 1; i <= numDefeated; ++i) {
                    opponents.at(player2Index)->levelUp(i, true);
                }
                
                textBox(tournamentMaster, "You have been challenged by: ");
                opponents.at(opponents.size() - 1)->printCharacter();
                textBox(tournamentMaster, "Would you like to fight?", "", "press key y / n");
                cin >> choice;
                cin.ignore();
                cout << endl;
                
                if(choice == "n") {
                    break;
                }
                
                bool defeated = players.at(player1Index)->battle(*opponents.at(player2Index), true, numDefeated);
                
                if(defeated) {
                    if(numDefeated > highScore) {
                        highScoreIndex = player1Index;
                        highScore = numDefeated;
                        textBox(tournamentMaster, playerName + " has set a new high score of " + to_string(highScore) + ".", "", pressEnter);
                        cin.get();
                    }
                    textBox(tournamentMaster, "Defeated: " + to_string(numDefeated), "Would you like to keep fighting?", "press key y / n");
                    cin >> choice;
                    cin.ignore();
                    cout << endl;
                }
                else {
                    if(numDefeated > highScore) {
                        highScore = numDefeated;
                    }
                    numDefeated = 0;
                    
                    textBox(tournamentMaster, "Couldn't handle it could you?", "", pressEnter);
                    cin.get();
                    break;
                }
                
            } while (choice == "y");
            
            continue;
            
        }
        else if (choice == "2") {
            
            if(players.size() > 1) {
                cout << endl;
                
                do {
                    
                    cout << right << " " << setfill('-') << setw(80) << " " << endl;
                    cout << left << setfill(' ') << setw(3) << "|";
                    cout << left << setfill(' ') << setw(77) << "FIGHTERS:" << "|" << endl;
                    for(int i = 0; i < players.size(); ++i) {
                        cout << left << setfill(' ') << setw(3) << "|";
                        cout << left << setfill(' ') << setw(77) << "[" + to_string(i + 1) + "] -- " + players.at(i)->getName() + " | Level " + to_string(players.at(i)->getLevel()) + " " + players.at(i)->getClassType() << "|" << endl;
                        pauseMilliseconds(200);
                    }
                    
                    cout << right << " " << setfill('-') << setw(80) << " " << endl;
                    pauseMilliseconds(200);
                    
                    textBox(tournamentMaster, "Who would you like to fight?", "", "press # key");
                    cin >> player2Index;
                    cin.ignore();
                    --player2Index;
                    
                    if(player2Index == player1Index) {
                        textBox(tournamentMaster, "You can't fight yourself.", "", pressEnter);
                    }
                    
                } while (player2Index == player1Index);
                
                players.at(player1Index)->battle(*players.at(player2Index), false, numDefeated);
                
            }
            else {
                textBox(tournamentMaster, "Looks like you don't have any friends to fight.", "(create a new character first)", pressEnter);
                cin.get();
                
                printMenu();
                cin >> choice;
                cin.ignore();
                cout << endl;
                continue;
                
            }
            
        }
        else if(choice == "3") {
            textBox(tournamentMaster, "The current high score is " + to_string(highScore) + ".", "Held by " + players.at(highScoreIndex)->getName() + ".", pressEnter);
            cin.get();
        }
        else if (choice == "4") {
            //training(&players, player1Index);
            players.at(player1Index)->training(trainerTitle, *trainingCharacter);
        }
        else if(choice == "5") {
            players.at(player1Index)->printCharacter();
            textBox("", "", "", pressEnter);
            cin.get();
        }
        else if(choice == "6") {
            players.at(player1Index)->resetStats();
            players.at(player1Index)->printActions();
            textBox("", "", "", pressEnter);
            cin.get();
        }
        else if(choice == "7") {
            changeName(tournamentMaster, *players.at(player1Index), players);
        }
        else if(choice == "8") {
            player1Index = loadCreatePlayer(tournamentMaster, players, playerName, classType);
        }
        else if (choice == "9") {
            
            if(player1Index == highScoreIndex) {
                textBox(tournamentMaster, "Master " + players.at(player1Index)->getName() + ", hope you left some for the rest of us.");
            }
            else {
                textBox(tournamentMaster, "Should have known you didn't have the stomach for this.", "Get this weakling away from me.");
            }
            break;
        }
        else {
            textBox("", "Invalid choice.", "", pressEnter);
            cin.get();
            
            printMenu();
            cin >> choice;
            cin.ignore();
            cout << endl;
            continue;
        }
            
        if(player1Index == highScoreIndex) {
            textBox(tournamentMaster, "Master " + players.at(player1Index)->getName() + ". What will it be?", "", pressEnter);
            cin.get();
        }
        else {
            textBox(tournamentMaster, "Huh, still alive?", "What will it be?", pressEnter);
            cin.get();
        }
        
        
    } while(true);
    //End main game loop
    
    
    //Save Game
    if(numDefeated > highScore) {
        highScore = numDefeated;
    }
    
    ofstream fout("players.txt");
    
    for(int i = 0; i < players.size(); i++) {
        fout << players.at(i);
        if(players.at(i) != nullptr) {
            delete players.at(i);
        }
        players.at(i) = nullptr;
    }
    fout << "High Score" << endl;
    fout << highScore << endl;
    if(highScoreIndex < 0) {
        fout << -1 << endl;
    }
    else {
        fout << highScoreIndex << endl;
    }
    fout.close();
    //End save game
    
    //Delete new allocated memory
    for(int i = 0; i < opponents.size(); ++i) {
        if(opponents.at(i) != nullptr) {
            delete opponents.at(i);
        }
        opponents.at(i) = nullptr;
    }
    
    delete trainingCharacter;
    trainingCharacter = nullptr;
    //end delete memory
    
    return 0;
    
}

