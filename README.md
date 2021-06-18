# Spreading V - Virus Simulation Project

# 2019 - 2020 Introduction to Programming Term Project

## Spreading V

**Description:**

In this Project You will simulate a laboratory experiment as a life game. You have a habitat that
contains randomly distributed entities. In our experiment our habitat will be a NxN square place.

Each entity has 5 different gates which can be named from { A,B,C,D,E,F,G,H } set.

The Spreading V can infect an entity if the entity has A or B gate. If the entity has 3 gates which are
named as A,B,C,D than this entity will die after 14 turns otherwise it will recover and get immune to
Spreading V. after 30 turns. Dead entities stay in habitat for five turns and be infectious. They can not
move.

Spreading V can infect from one entity to other if they are closer than 3 units (in square form). An
entity becomes infectious after 3 turn.

Your simulation will take the start information from input.txt file which will be on the same file with
you executable. This file include information about habitat constants, entities and their movements
in turns.

Your simulation will write an output.txt file which will show the infected and died entities and last
situation of the habitat. Also, after each turn you will fill another file “turns.txt”. This file shows a
brief outcome for each turn.

An example of the input and output files are below: We have a 5x5 habitat and includes 3 entity in
this example. İt is a short description so the movements are made just for three steps. Test case
should be made for more turns. Since our habitat is to small and each entity is close to each other
infected entity can easily infect the others. But the infection will occur after 3 turns so we do not see
any infection in three turns. “X” shows infected entities, “O” for healthy entities, “D” for dead ones.

Your application must not include any console input command. Your app directly read the input file,
generate output.txt and turns.txt files and close itself silently. If you prefer you can draw turns on the
screen but just the file version will be graded.

**Project deliveries will be done over Google Classroom Web Page and only one code file named
with your student number must be uploaded. Any other upload types will be discarded. Your file
must include your name and number as comment at the beginning. (File ex: 1306200021.cpp)**

**Do not place any other code file or dependencies for your project.**

Examples are on the next pages;


### EXAMPLE 1:

### INPUT.TXT

size 5
turn_count 3
entity 1 ACDEF 2x2 infected
entity 2 BDFHC 4x
entity 3 CDHGF 5x
turn 1 2x3 4x5 5x
turn 2 3x3 4x4 5x
turn 3 3x4 4x3 5x

OUTPUT.TXT

Normal : 2
Infected : 1
Dead : 0
Recovered: 0
entity 1 3x4 infected
entity 2 4x3 normal
entity 3 5x2 normal

TURNS.TXT

Turn 1 :
-------

- -
- X -
- -
- O-
- O -
- ------
Turn 2:
-------
- -
- -
- X -
- O -
- O -
-------
Turn 3 :
-------
- -
- -
- X -
- O -
- O -
-------


EXAMPLE 2:

INPUT.TXT

size 15
turn_count 25
entity 1 ACDEF 12 x 1 2 infected
entity 2 BDFHC 1 4x 15
entity 3 CDHGF 5x
entity 4 DEFGA 1x
turn 1 1 2x 13 1 4x 14 5x4 1x
turn 2 1 3x 13 1 4x 1 4 5x3 1 x
turn 3 1 3x 14 1 4x 1 3 5x2 1x
turn 4 14x14 14x12 5x1 1x
turn 5 14x13 14x12 5x2 2x

....


