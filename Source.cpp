//ASIM KAYMAK
//1306180004
//Date: 23.05.2020
//Development Environment: Visual Studio2019
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Habitat
{

private:
    int** area;
    int n;
public:

    void createHabitat(int);
    void turnsAdd(int, int, int);
    void turnsShow(int);
    void turnsClear();
    int get_Size() const;
};


class Entity : private Habitat {
private:

public:
    void createEntity(string, bool, int);
    int creatingFirst = -1;
    vector<char>gates;
    vector<vector <int>> positions;
    int turns_count = 0;
    bool isInfected = false;
    bool isNormal = true;
    bool isDeath = false;
    bool canBeInfected = false;
    int firstInfected = -1;
    bool canBeDeath = false;
    bool isInfectous = false;
    int deathPosition[2] = { -1,-1 };
    char status = 'O';
    int infStartTurnNumber = -1;
    int deathStartTurnNumber = -1;
    bool ExactlyDeath = 0;
    int ExactlyInfected = -1;
    bool recovered = 0;
    bool isChar(char) const;
    void takeStep(string);
    int get_positions_X() const;
    int get_positions_X_death() const;
    int get_positions_Y_death() const;
    int get_positions_Y() const;
    int str_to_int(string);
    //isChar yerine a veya b olup olmadýðýna bak yani isInfected
    //diðer durumlarý kontrol ettir gate kapýlar 
};

void Entity::createEntity(string x, bool isInfected, int max_turn_count) {
    int gatescounter = 0;
    for (int i = 0; i < x.size(); i++) {
        this->gates.push_back(x[i]);
        if (x[i] == 'A' || x[i] == 'B' || x[i] == 'C' || x[i] == 'D') {
            gatescounter++;
        }
    }

    if (this->isChar('A') || this->isChar('B')) {


        this->canBeInfected = true;

    }
    else
        this->canBeInfected = false;
    if (gatescounter >= 3 && canBeInfected == true) {
        this->canBeDeath = true;
    }

    if (isInfected) {
        this->status = 'X';
        this->ExactlyInfected = 2;
        this->firstInfected = 1;
        this->infStartTurnNumber = 0;
        if (this->canBeDeath) {
            this->deathStartTurnNumber = 0;
            this->creatingFirst = 1;
        }
    }

    this->positions.resize(max_turn_count);
}
bool Entity::isChar(char x) const {
    for (int i = 0; i < this->gates.size(); i++) {
        if (this->gates[i] == x) return true;

    }
    return false;
}
void Entity::takeStep(string position) {
    string temp = "";
    int x, y;
    //12x13
    //12
    //13
    int m = 0;
    if (this->recovered == 1) {
        this->positions.resize(this->positions.size() + 1);
        if (this->isDeath == false && this->ExactlyDeath == false) {
            for (int i = 0; i < position.size(); i++) {
                if (position[i] == 'x') {
                    x = this->str_to_int(temp);
                    temp = "";
                }
                else {
                    temp += position[i];
                }



            }
            y = this->str_to_int(temp);
            this->positions[this->turns_count].push_back(x);
            this->positions[this->turns_count].push_back(y);
            this->turns_count++;
        }
    }

    else if ((this->turns_count + 1 > this->infStartTurnNumber + 14) && (this->canBeDeath == 1) && (this->infStartTurnNumber != -1) && (this->creatingFirst == 1)) {
        m = 5;
    }
    else if ((this->turns_count + 1 > this->infStartTurnNumber + 14) && (this->canBeDeath == 1) && (this->infStartTurnNumber != -1) && (this->creatingFirst == -1)) {
        m = 5;
    }
    else {
        this->positions.resize(this->positions.size() + 1);
        if (this->isDeath == false && this->ExactlyDeath == false) {
            for (int i = 0; i < position.size(); i++) {
                if (position[i] == 'x') {
                    x = this->str_to_int(temp);
                    temp = "";
                }
                else {
                    temp += position[i];
                }



            }
            y = this->str_to_int(temp);
            this->positions[this->turns_count].push_back(x);
            this->positions[this->turns_count].push_back(y);
            this->turns_count++;
        }
    }


    /* if (this->isDeath == true && this->ExactlyDeath == false) {
         int x1 = this->get_positions_X();
         int y1 = this->get_positions_Y();
         this->positions[this->turns_count].push_back(this->positions[this->turns_count - 3][0]);
         this->positions[this->turns_count].push_back(this->positions[this->turns_count - 3][0]);
         this->turns_count++;*/
}
int Entity::get_positions_X() const {

    return this->positions[this->turns_count - 1][0];

}
int Entity::get_positions_Y() const {

    return this->positions[this->turns_count - 1][1];

}
int Entity::get_positions_X_death() const {
    return this->positions[this->turns_count - 1][0];


}
int Entity::get_positions_Y_death() const {

    return this->positions[this->turns_count - 1][1];


}
int Entity::str_to_int(string x) {
    int number = 0;

    for (int i = 0; i < x.size(); i++) {
        number *= 10;
        number += x[i] - 48;
    }
    return number;
}
void Habitat::createHabitat(int n) {
    this->area = new int* [n];
    for (int i = 0; i < n; ++i)
        this->area[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            this->area[i][k] = 0;
        }
    }
    this->n = n;
}
void Habitat::turnsShow(int turn) {
    if (turn == 1) {
        remove("turn.txt");
    }
    ofstream turns("TURNS.TXT", ios::app);
    turns << "Turn " << turn << ":" << endl;
    for (int i = 0; i < this->n + 2; i++) {
        if (i == 0 || i == this->n + 1) {
            for (int j = 0; j < this->n + 2; j++) {
                turns << "-";
            }
            turns << endl;
        }
        else {
            turns << "-";
            for (int j = 0; j < this->n; j++) {

                if (this->area[i - 1][j] == 'O') {
                    turns << "O";
                }
                else if (this->area[i - 1][j] == 'X') {
                    turns << "X";
                }
                else if (this->area[i - 1][j] == 'D') {
                    turns << "D";
                }
                else if (this->area[i - 1][j] == '0') {
                    turns << "0";
                }
                else {
                    turns << " ";
                }

            }
            turns << "-";
            turns << endl;
        }

    }
}
void Habitat::turnsAdd(int x, int y, int z) {
    this->area[x - 1][y - 1] = z;
}
void Habitat::turnsClear() {
    for (int i = 0; i < this->n; i++) {
        for (int k = 0; k < this->n; k++) {
            this->area[i][k] = 0;
        }
    }
}
int Habitat::get_Size() const {
    return this->n;
}

int string_to_int(string);
void turnsCompleter(vector<Entity>&, Habitat, int, int);
void entitiesController(vector<Entity>&, int, int, int);
static int recover = 0;
void output_formatter(vector <Entity>& entities, int);
int main() {

    string line = "";
    int max_turn_count = 0;
    int entity_count = 0;
    Habitat habitat;
    int turnStep = 0;
    vector<Entity>entities(1000);
    ifstream inputFile("INPUT.TXT");
    if (inputFile.is_open()) {

        while (getline(inputFile, line)) {
            vector<string>lineVector;
            string temp = "";
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ' ') {
                    lineVector.push_back(temp);

                    temp = "";
                }
                else {
                    temp += line[i];
                }


            }

            lineVector.push_back(temp);
            int size = 0;
            if (lineVector[0] == "size") {
                size = 0;
                for (int i = 0; i < lineVector[1].size(); i++) {
                    size *= 10;
                    size += (int)lineVector[1][i] - 48;
                }
                habitat.createHabitat(size);
            }
            else if (lineVector[0] == "turn_count") {
                size = 0;
                for (int i = 0; i < lineVector[1].size(); i++) {
                    size *= 10;
                    size += (int)lineVector[1][i] - 48;
                }
                max_turn_count = size;
            }
            else if (lineVector[0] == "entity") {
                if (lineVector[lineVector.size() - 1] == "infected") {
                    entities[entity_count++].createEntity(lineVector[2], 1, max_turn_count);

                }
                else {
                    entities[entity_count++].createEntity(lineVector[2], 0, max_turn_count);
                }


            }
            else if (lineVector[0] == "turn") {
                for (int i = 0; i < entity_count; i++) {

                    entities[i].takeStep(lineVector[2 + i]);
                }

                turnStep++;
                turnsCompleter(entities, habitat, entity_count, turnStep);
                entitiesController(entities, entity_count, size, turnStep);



            }




        }

        output_formatter(entities, entity_count);
        inputFile.close();

    }

}
int string_to_int(string x) {
    int number = 0;
    for (int i = 0; i < x.size(); i++) {
        number *= 10;
        number += x[i] - 48;
    }
    return number;
}
void turnsCompleter(vector<Entity>& entities, Habitat habitat, int entity_count, int turnStep) {
    int turn = turnStep;

    for (int i = 0; i < entity_count; i++) {
        if (entities[i].ExactlyDeath == 0) {
            habitat.turnsAdd(entities[i].get_positions_X(), entities[i].get_positions_Y(), entities[i].status);
        }



    }




    habitat.turnsShow(turn);
    habitat.turnsClear();
}

void entitiesController(vector<Entity>& entities, int entity_count, int size, int turnStep) {
    int turnNumber = turnStep;
    for (int i = 0; i < entity_count; i++) {

        if (entities[i].ExactlyDeath == 1) {
            continue;
        }
        else if (entities[i].isDeath == 1 && turnNumber >= 5 + entities[i].deathStartTurnNumber && entities[i].deathStartTurnNumber != -1) {
            entities[i].isInfected = 0;
            entities[i].ExactlyInfected = -1;
            entities[i].status = ' ';
            entities[i].deathStartTurnNumber = -1;
            entities[i].isNormal = 0;
            entities[i].isDeath = 0;
            entities[i].ExactlyDeath = 1;
        }
        else if (entities[i].isDeath == 1) {
            entities[i].status = 'D';
            entities[i].ExactlyInfected = -1;
        }
        else if (entities[i].recovered == 1) {

            entities[i].recovered = 1;
            entities[i].status = '0';
            entities[i].infStartTurnNumber = -1;
            entities[i].ExactlyInfected = -1;
            entities[i].isInfected = 0;
            entities[i].canBeDeath = 0;
            entities[i].canBeInfected = 0;
            entities[i].isNormal = 1;
            entities[i].isDeath = 0;
        }
        else if ((turnNumber > entities[i].infStartTurnNumber + 30) && (entities[i].infStartTurnNumber != -1) && (entities[i].canBeDeath == 0)) {
            recover++;
            entities[i].recovered = 1;
            entities[i].status = '0';
            entities[i].infStartTurnNumber = -1;
            entities[i].ExactlyInfected = -1;
            entities[i].isInfected = 0;
            entities[i].canBeDeath = 0;
            entities[i].canBeInfected = 0;
            entities[i].isNormal = 1;
            entities[i].isDeath = 0;
        }
        else if ((turnNumber > entities[i].infStartTurnNumber + 14) && (entities[i].canBeDeath == 1) && (entities[i].infStartTurnNumber != -1)) {

            entities[i].status = 'D';
            entities[i].deathStartTurnNumber = turnNumber;
            entities[i].isDeath = 1;
            entities[i].isNormal = 0;
            entities[i].isInfected = 1;

        }
        else if ((entities[i].isInfected == 1) || ((turnStep > entities[i].ExactlyInfected) && (entities[i].ExactlyInfected != -1) && (entities[i].ExactlyInfected != 0))) {

            entities[i].status = 'X';
            entities[i].isInfected = 1;
            entities[i].isNormal = 0;
            for (int j = 0; j < entity_count; j++) {

                if (entities[j].canBeInfected == true && entities[j].isInfected == 0 && entities[j].isDeath == 0 && entities[j].infStartTurnNumber == -1 && entities[j].ExactlyInfected == -1 && entities[j].recovered == 0 && turnNumber > 2) {
                    int x1 = entities[i].get_positions_X();
                    int y1 = entities[i].get_positions_Y();
                    int x2 = entities[j].get_positions_X();
                    int y2 = entities[j].get_positions_Y();
                    if (x1 >= x2 - 3 && x1 <= x2 + 3 && y1 >= y2 - 3 && y1 <= y2 + 3) {
                        if (entities[j].infStartTurnNumber == -1) {
                            //cout << entities[i].get_infStartTurnNumber();
                            entities[j].infStartTurnNumber = turnStep;
                            entities[j].ExactlyInfected = 2 + turnStep;
                            entities[j].status = 'X';
                            //cout << entities[i].get_infStartTurnNumber();
                        }
                    }





                }

            }
        }
        else if ((entities[i].ExactlyInfected != -1) && (entities[i].ExactlyInfected != 0) && turnStep > entities[i].ExactlyInfected) {

            entities[i].status = 'X';
            entities[i].isInfected = 1;
            entities[i].isNormal = 0;
        }
        else if (entities[i].canBeInfected == true && entities[i].isInfected == 0 && entities[i].isDeath == 0 && entities[i].infStartTurnNumber == -1 && entities[i].ExactlyInfected == -1 && entities[i].recovered == 0 && turnNumber > 2) {

            for (int j = 0; j < entity_count; j++) {

                if ((entities[j].isInfected == true || entities[j].isDeath == true) || ((turnStep > entities[i].ExactlyInfected) && (entities[i].ExactlyInfected != -1) && (entities[i].ExactlyInfected != 0))) {
                    int x1 = entities[i].get_positions_X();
                    int y1 = entities[i].get_positions_Y();
                    int x2 = entities[j].get_positions_X();
                    int y2 = entities[j].get_positions_Y();
                    if (x1 >= x2 - 3 && x1 <= x2 + 3 && y1 >= y2 - 3 && y1 <= y2 + 3) {
                        if (entities[i].infStartTurnNumber == -1) {
                            //cout << entities[i].get_infStartTurnNumber();
                            entities[i].infStartTurnNumber = turnStep;
                            entities[i].ExactlyInfected = 2 + turnStep;
                            entities[i].status = 'X';
                            //cout << entities[i].get_infStartTurnNumber();
                        }
                    }





                }

            }

        }


    }




}
void output_formatter(vector <Entity>& entities, int entitiy_count) {
    ofstream outputtxt("OUTPUT.TXT");
    int normal = 0, death = 0, infected = 0, recovered = 0;
    for (int i = 0; i < entitiy_count; i++) {
        if (entities[i].isDeath == 1 || entities[i].ExactlyDeath == 1) {
            death++;
        }
        else if (entities[i].isInfected == 1) {
            infected++;
        }
        else if (entities[i].isInfected == 0 && entities[i].ExactlyDeath == 0 && entities[i].isNormal == 1 && entities[i].isDeath == 0 && entities[i].recovered == 1) {
            recovered++;
        }
        else {
            normal++;
        }

    }
    outputtxt << "Normal    : " << normal << endl;
    outputtxt << "Infected  : " << infected << endl;
    outputtxt << "Dead      : " << death << endl;
    outputtxt << "Recovered : " << recovered << endl;
    for (int i = 0; i < entitiy_count; i++) {
        if (entities[i].isDeath == 1 || entities[i].ExactlyDeath == 1) {
            outputtxt << "entity " << i + 1 << " " << entities[i].get_positions_X_death() << "x" << entities[i].get_positions_Y_death() << " " << "dead" << endl;
        }

        else if (entities[i].isInfected == 0 && entities[i].ExactlyDeath == 0 && entities[i].isNormal == 1 && entities[i].isDeath == 0 && entities[i].recovered == 1) {
            outputtxt << "entity " << i + 1 << " " << entities[i].get_positions_X() << "x" << entities[i].get_positions_Y() << " " << "immune" << endl;
        }
        else if (entities[i].isInfected == 1) {
            outputtxt << "entity " << i + 1 << " " << entities[i].get_positions_X() << "x" << entities[i].get_positions_Y() << " " << "infected" << endl;
        }
        else {
            outputtxt << "entity " << i + 1 << " " << entities[i].get_positions_X() << "x" << entities[i].get_positions_Y() << " " << "normal" << endl;
        }
    }
    outputtxt.close();
}