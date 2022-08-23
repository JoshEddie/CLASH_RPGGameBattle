#include "functions.hpp"

void pauseMilliseconds(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void textBox(string name, string line1, string line2, string action, string line3, string line4) {
    
    for(int i = 0; i < name.length(); ++i) {
        name.at(i) = toupper(name.at(i));
    }
    
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    if(name.length() > 0) {
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << name + ": " << "|" << endl;
    }
    if(line1.length() > 0) {
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << line1 << "|" << endl;
    }
    if(line2.length() > 0) {
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << line2 << "|" << endl;
    }
    if(line3.length() > 0) {
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << line3 << "|" << endl;
    }
    if(line4.length() > 0) {
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << line4 << "|" << endl;
    }
    if(action.length() > 0) {
        cout << "|" << right << setfill(' ') << setw(77);
        cout << "[" + action + "]";
        cout << right << setfill(' ') << setw(3) << "|" << endl;
    }
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    
}

//Generates a random name for computer players by taking an random adjetive combined with a random name. Approximately 30,000+ options.
string nameGenerator() {
    
    string adjetive, name, job;
    string randomName;
    
    vector<string> adjetives{"Good looking", "Young", "Excited", "Little", "Old", "Creative", "Cheerful", "Friendly", "Arrogant", "Devious", "Lazy", "Finicky", "Grumpy", "Vain", "Stubborn", "Burned", "Sleepy", "Tall", "Short", "Diligent", "Adventurous", "Humble", "Trustworthy", "Strong", "Wealthy", "Kind", "Generous"
    };
    
    vector<string> jobs{"Writer", "Drunkard", "Butcher", "Dancer", "Blacksmith", "Scholar", "Dreamer", "Trickster", "Farmer", "Baker", "Tanner", "Carpenter", "Teacher", "Architect", "Doctor", "Bard", "Tailor", "Brick Maker", "Storyteller", "Hunter", "Juggler", "Scientist"
    };
    
    vector<string> names{"Bob", "August", "Florian", "Gregoria", "Godfrey", "Regina", "Winifred", "Otto", "Lucian", "Sebastian", "Leopold", "Gisela", "Beatrice", "Anabel", "Athena", "Alexander", "Adonis", "Penelope", "Daphne", "Alexandra", "Cassandra", "Iris", "Thalia", "Rhea", "Atlas", "Jason", "Titus", "Vulcan", "Maximus", "Alice", "Amelia", "Isla", "Freya", "Poppy", "Chloe", "Ruby", "Sophia", "Jane", "Nancy", "Archie", "Eva", "Henry", "James", "Jack", "Oliver", "Edward", "Charlie", "Noah", "Leo", "Frederick"
    };
    
    adjetive = adjetives.at(rand() % adjetives.size());
    job = jobs.at(rand() % jobs.size());
    name = names.at(rand() % names.size());
    
    randomName = adjetive + " " + job + " " + name;
    return randomName;
    
}

void printBattleMenu() {
    
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "CHOOSE ACTION:" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[1] -- Attack" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[2] -- Flee" << "|" << endl;
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    cout << endl;
    
}

void printMenu() {
    
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "CHOOSE ACTION:" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[1] -- Fight Computer" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[2] -- Fight a Friend" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[3] -- High Score" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[4] -- Training" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[5] -- Show Stats" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[6] -- Show Attacks" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[7] -- Change Name" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[8] -- Load/Create New Player" << "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "[9] -- Exit" << "|" << endl;
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    
}
