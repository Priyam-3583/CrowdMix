# CrowdMix

### Crowd Voted DJ Set Planner with BPM Mix Check

---

## Project Description

CrowdMix is a C-based, command-line application designed to simulate how a crowd can help a DJ plan a set. It keeps a built-in library of songs, collects votes from the crowd for each song, and arranges the songs into a ranked set list.

After the set list is created, the program checks how well neighbouring songs can be mixed together using their BPM (beats per minute). Transitions where the tempo difference is too large are flagged for the DJ, so the crowd gets a say in the music while the DJ still gets technical guidance.

---

## Aim of the Project

The primary purpose of CrowdMix is to show how fundamental C programming concepts can be applied to a fun, real-world-inspired problem from the music and party scene.

The project aims to:

- Store song information (title, BPM, votes) in an organized way.
- Collect crowd votes for every song in the library.
- Reject invalid votes such as letters or negative numbers.
- Rank the songs from most voted to least voted.
- Leave out songs that received no votes, so the set list only has songs the crowd wanted.
- Show each song's share of the total votes.
- Identify the crowd favourite, including ties.
- Help the DJ by checking whether neighbouring songs are easy to mix.
- Demonstrate the use of fundamental C concepts in a practical program.

---

## Key Features

### 1. Song Library
Maintains a built-in library of six songs. Each song stores its title, BPM, and the number of votes it receives.

### 2. Crowd Voting with Input Validation
Shows the song library and asks for the number of votes each song received, one song at a time. If the user types letters or a negative number, the program rejects the input and asks again for the same song.

### 3. Ranked Set List
Sorts the songs from the highest votes to the lowest using bubble sort. Songs that receive zero votes are left out of the final set list. If nobody votes at all, the program shows a total of 0 votes and exits. The result is shown as a table with rank, song, BPM, votes, and each song's percentage share of the total votes.

### 4. Crowd Favourite and Total Votes
Displays the most voted song. If two or more songs share the highest vote count, all of them are announced as the crowd favourites. The total number of votes is also displayed.

### 5. BPM Mix Check (Unique Feature)
Checks every pair of neighbouring songs in the set list and compares their BPM.

- BPM difference of 8 or less: **Smooth**
- BPM difference of more than 8: **HARD TO MIX**

Each transition also shows the tempo direction: **Speed UP**, **Slow DOWN**, or **Same tempo**.

---

## C Concepts Used

The project uses several fundamental programming concepts:

- **Structures:** For grouping a song's title, BPM, and votes together.
- **Arrays of Structures:** For storing the built-in song library.
- **Loops:** For displaying songs, taking votes, sorting, and running the mix check.
- **Conditional Statements:** For deciding between Smooth and HARD TO MIX, and for tempo direction.
- **Sorting:** Bubble sort to rank songs by votes.
- **Input Validation:** Using the return value of `scanf` and clearing wrong input with `getchar` to keep the program reliable.
- **Formatted Output:** Using width and precision in `printf` to display clean tables and percentages.

---

## How to Run

Compile and run the program using GCC:

```
gcc Main.c -o crowdmix
./crowdmix
```

---

## Sample Run

Votes entered (in library order: Levels, Titanium, Animals, WakeMeUp, Closer, Faded): `6 5 9 1 15 2`

```
========== FINAL SET LIST ==========
Rank  Song        BPM   Votes   Share
------------------------------------
1     Closer      95    15      39.5%
2     Animals     128   9       23.7%
3     Levels      126   6       15.8%
4     Titanium    126   5       13.2%
5     Faded       90    2       5.3%
6     WakeMeUp    124   1       2.6%
------------------------------------

Crowd Favourite: Closer (15 votes)
Total Votes: 38

============= MIX CHECK ============
Closer     -> Animals    : HARD TO MIX (Speed UP)
Animals    -> Levels     : Smooth (Slow DOWN)
Levels     -> Titanium   : Smooth (Same tempo)
Titanium   -> Faded      : HARD TO MIX (Slow DOWN)
Faded      -> WakeMeUp   : HARD TO MIX (Speed UP)
```

---

## Limitations and Future Scope

- The song library is built into the program and contains six songs.
- Data is not saved after the program ends.
- Future versions could add a menu, let the DJ add new songs, save set lists to a file, and automatically reorder songs to reduce hard transitions.

---

## Conclusion

CrowdMix demonstrates how fundamental C programming concepts can be combined to build a complete, interactive command-line program. Through crowd voting, ranking, input validation, and a BPM-based mix check, the project shows how programming can solve a practical problem in a creative way.

It serves as an academic demonstration of structured data management, sorting, decision-making, and problem-solving using the C programming language.

---

- **Project Name:** CrowdMix
- **Project Domain:** Music and DJ Set Planning
- **Programming Language:** C
- **Application Type:** Command-Line Application
- **Project Category:** Academic Semester Project
- **Author:** Priyam Arya
