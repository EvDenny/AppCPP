# ![picture](images/cpp.sprite.png) $\textcolor{#4a49af}{\tt ^{APPLICATION}}$

[![CodeFactor](https://www.codefactor.io/repository/github/evdenny/appcpp/badge/master)](https://www.codefactor.io/repository/github/evdenny/appcpp/overview/master) [![CodeQL](https://github.com/EvDenny/AppCPP/actions/workflows/codeql.yml/badge.svg)](https://github.com/EvDenny/AppCPP/actions/workflows/codeql.yml) [![Windows](https://svgshare.com/i/ZhY.svg)](https://svgshare.com/i/ZhY.svg) [![Linux](https://svgshare.com/i/Zhy.svg)](https://svgshare.com/i/Zhy.svg) [![PyPI license](https://img.shields.io/pypi/l/ansicolortags.svg)](https://pypi.python.org/pypi/ansicolortags/)

[![GitHub commits](https://badgen.net/github/commits/EvDenny/AppCPP)](https://GitHub.com/EvDenny/AppCPP/commit/) [![GitHub latest commit](https://badgen.net/github/last-commit/EvDenny/AppCPP)](https://GitHub.com/EvDenny/AppCPP/commit/) [![GitHub issues](https://img.shields.io/github/issues/Naereen/StrapDown.js.svg)](https://GitHub.com/Naereen/StrapDown.js/issues/) 

[![Evan's top languages](https://github-readme-stats.vercel.app/api/top-langs/?username=EvDenny&layout=compact)](https://github.com/anuraghazra/github-readme-stats)

$$\LARGE \tt CURRENT~VERSION:$$

$$\LARGE \underline{\LARGE{~0.5.1\_{\normalsize / 1 7}}}\small{.branch(galaxy)}_{\tt \tiny STABLE}$$ 

$${\LARGE \colorbox{#350999}{\tt \color{#FFFFFF}{\large Contributers}}\brack{\tt Evan~Denny}}$$ 

$$ \tt Last~~Updated~~~On~~~~ \underline {9/20/2022} $$

# Latest Changes

#### Version 0.5.1-17:
 
 - Replaced mdy.cpp with revamped **mdy2.cpp**
    -  *Object-Oriented*
    -  Increased Readability
    -  Fixed previous bug from mdy.cpp
 -  Only a few changes need to be made to mdy2.cpp to have a fully working tool for the Tools Section of the program
 -  New ideas for tools added to README.md
 -  *Documentation for mdy2.cpp should be added for practice designing code for other programmers to read*

---

$$\LARGE{ \underline {\frak{Games~\And~\negthinspace ~Tools}}}$$

This application is currently a **work in progress**. It is designed to compress my porfolio of games and tools built in C $\negthinspace ^+$ $\negthickspace ^+$ *(from simple to complex)* on a single app to test my milestones in my learning of C $\negthinspace ^+$ $\negthickspace ^+$ programming.

Included are demonstrations of my skills and examples of my abilities to *problem solve* and implement solutions to self-assigned tasks including creating frameworks, tools, and using C $\negthinspace ^+$ $\negthickspace ^+$ *APIs* like **OpenGL** and **SFML**.

The following programs have been incorporated into a single application for ease of access and demonstration.

##### Games

- \[x] Guessing Game
- \[x] Hangman
- \[ ] Tic-Tac-Toe | Barely Started

##### Tools

- \[ ] MDY Calculator | 95% Complete
- \[ ] Website Parser | Looking into Web Scraping with C++ (Python is perfect for this so it might be an opportunity to use Python in C++ or vice-versa)
- \[ ] RNG (Random Number Generator) | Already use Mersenne Twister Engine for Guessing Game, woring on making the engine into a tool for customizing the uniform_int_distribution for other forms of distribution and different ranges and types of ranges
- [ ] File manipulation (Creationo, Reading, Writing) | Still learning fstream

## *Games* Section:

### Guessing Game

A random number is randomly selected with a mersenne twister engine between 1 and 100.
> Guess the number within *10 tries* to beat the **high score!**

Score updates upon achieving said goal.
Every guess gives you a hint as to how close the number is.

>The closer you are the hotter it gets, the further you are the colder it gets.
>>It's been modified several times to make it more difficult to guess the number.
>>>Specifically, as you get precise with your guesses, you have less of an idea of where the number is.

### Hangman

This is a multiplayer game. 

You **need** at least one other player to participate.

>The game takes two inputs from one player who knows the phrase or word chosen.
>>That person can choose to give a hint with the second input. You can leave this option blank.

*All letters are converted to lowercase letters to avoid confusion between the guess and the answer.*

When the phrase or word is entered, an answer key is created in the form of a `vector<char>`.

Any extra common `ASCII` characters like '!?/\'.,"' and the space (' ') are removed from the vector.

The vector is converted to lowercase, sorted alphabetically, duplicates are removed, and resized to fit the all the characters if duplicates were present.

#### Let's say I enter a phrase: "Who watches the watchmen?"

The program will convert the string input into a cstring array `[W, h, o, ... e, n, ?]`.

The vector is copied to a vector called charsLower where the letters are converted to lowercase `{w, h, o ... e, n, ?}`.

Non-lowercase-alphabet characters are removed:
`{w, h, o ... m, e, n, n}`

>>(The function passes the vector by address so the '?' is converted into the character indexed previously to it. In this case that's 'n'. This isn't a problem though because in the next steps we remove duplicates!)

The vector is sorted:

`{ a, a, c, c, e, e, e, h, h, h, h, m, n, n, o, s, t, t, t, w, w, w }`
>> (There are two 'n's because of the previous step.)

`std::unique_copy` to a different vector. This will remove duplicates, resize our vector to fit each of the alphabetical characters used. 

`{a, c, e, h, m, n, o, s, t, w}` is our `vector<char>` called 'answer' (Key).

`'acehmnostw'` are all the characters used from the alphabet. 

##### **Now you're probably wondering why I explained all this?**

Well, between the first player entering a phrase and the second player guessing their first letter, all of the above is executed and the game is instantiated.

Here's an example of what the user will experience:

>Terminal/Command Line Interface

```bash
     |----|
          |
          |
          |   
__________|

_ _ _  _ _ _ _ _ _ _  _ _ _  _ _ _ _ _ _ _ _ ?
Hint: WWTW?
Guess a letter: |
```

> The guesser has 6 lives (for the **HEAD**, **LEFT_ARM**, **RIGHT_ARM**, **TORSO**, **LEFT_LEG**, **RIGHT_LEG**).

Every time the guesser enters a non-alphabetical character like a number, the program evaluates the character and if it isn't 'a-z' or 'A-Z' the guesser will receive a warning 'Invalid input' and won't lose a life.

*Currently, entering numbers will trigger this feature, but other types of characters like '!' will not.* `<[BUG 0.5.1_02]>`

>Every time the guesser enters an incorrect character, it is appended to a vector<char> called 'wrong'. 
>>If a duplicate letter is guessed, the player doesn't lose a life and is warned 'You've already guessed that letter'.
>With an incorrect guess, the players life decreases by 1 (starting from 6).

If they guess correctly, the letter is added to a `vector<char>` called 'right' and the vector is sorted alphabetically. 
>Duplicate guesses are handled the same as for the *'wrong'* vector.

*This is done as a means for the guesser to fully guess the phrase and achieve a **win** state by matching their 'right' vector to the 'answer' vector.*

Every time a guess is made, the entire screen is cleared and redrawn with a function `HANGMAN::redraw()`.

Understanding my reasoning for every decision I made while creating the game involves learning about all of the functions that parse `vectors<char>` to create the experience. 
We know of a few vectors from previous statements. 
>These are 'answer' which is the answer key, 'right' which accepts and sorts correct characters as to match the 'answer vector, 'wrong' which is used to store incorrect letters and display them to the guesser to remind them of guesses they've already made.

We know that a cstring array [] is created when the first player enters the phrase, but that vector is also used in the redraw() function. 
>Not the first vector (which I called 'chars'), but the second vector 'charsLower'. 
>>This vector is used to draw the '_' underscores at each place where there is a letter. Followed by a ' ' space. 
>>Whenever a ' ' or a non-alphabet non-numeric commonly used ASCII character like '?', that ' ' or '?' is printed (followed by a space).

This is to make any symbols the first player uses actually visible without having to guess each symbol. 
`(The only thing the guesser should have to guess is 'a-z' or 'A-Z')`

You may also wonder what happens when a capital letter in input by the guesser. 
>We know that the lowercase letters are used to display the REDACTED phrase to the guesser. 
>>Well, every input is first passed through a function converting the letter to lowercase, which does nothing if the letter is already lowercase or is a number (1-9) or a symbol ('?!#').

>redraw() is essentially the mainloop of the program. 
>>This means that while the function involves drawing to the terminal screen, it also involves other tasks (like clearing the screen or checking the 'right' vector against the 'answer' vector).

## The Mainloop:

>HANGMAN::redraw() is the mainloop of the program.

**displayGallows()** --> Based on the number of lives the guesser(s) has/have, a different drawing is displayed.

**displayWrongVector()** --> The 'wrong' vector is parsed and for each index, the letter is written to std::cout

**displayLines()** --> This displays the underscores (letters), spaces, and symbols in the phrase entered. 
>When parsed, each letter is parsed again against the 'right' vector, and if charsLower[index] == right[index(2)] the letter is drawn to std::cout with an underline and the function is continue;d to prevent additional '_' underscores from being drawn.

**getInput()** --> The 'letter' variable is cleared and the program asks the guesser for a letter. 
>If a single letter is input, the 'letter' is assigned to a vector ('right' or 'wrong') or thrown away in the case of a duplicate.

**system('clear')** or **system('cls')** on Windows. 
>This preps the program for redrawing.

### check():

**check()** --> 'right' == 'answer' after right is sorted. If **true**, the **win()** function is called which ends the game only if every correct letter is guessed. This then sets the Boolean *win* to **true** from its instantiated state **false**. 

The letter is also parsed against 'answer' by itself to determine if it will be appended to 'right' or 'wrong'. 
>Before appendation, the letter is then parsed against the selected vector.
>>If at any point, 'letter' == right/wrong[index(s)], the program does not append the letter.

Based on the input, **'Correct!'**, **'Incorrect!'**, *'You've already guessed that letter'*, or **'Invalid input'** is drawn for the guesser.
>The main thread is then paused for a bit for said person to comprehend the string.

If any incorrect letter input and isn't a duplicate of vector<char> wrong[index], the number of lives the guesser has is decreased.

>The function then hands the thread back to the Mainloop to redraw the screen.
>> (The Mainloop is wrapped in a do{}while() loop where the while condition is (!*win*).
>> If the guesser's lives is reduced to 0, the *lose()* function is called and the do{} loop is broken.)

*This function is included towards the end of the getInput() function to evaluate the game states.*

###### DEBUGGING

// PrintAns() --> This function is purposefully commented out of the Mainloop but is included nonetheless. This is for debugging purposes. It displays the 'answer' vector and the 'right' vector (with a divider between them) to the guesser to make sure the program is running correctly.

$${{{{\underset{{\LARGE\boxed{\ulcorner~~~\color{yellow}{\tt_{Front~End~Development~INCOMPLETE}}~~~\urcorner}}}{\boxed{\ulcorner_{\LARGE \tt \color{blue}{~~~ }{Lead{~}Developer}{~~~~}}\urcorner}}}~~\boxed\checkmark~\tt \large E{_D^J}}}}$$
