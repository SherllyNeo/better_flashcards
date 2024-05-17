# Better flashcards
This is a cli app written in C

Anki style

It is a minimalist study app that allows you to select a deck of flashcards and study them.
You get shown the prompt, then can reveal the answer.
You get the option to say if you got it correct or not.

If it correct again, it will ask you again in a day.
If it is correct again, it will ask you again in a week.
If you are correct again, it will ask you again in about a month.

If you get something incorrect, it will reset it to be asked again immedately.

Each deck is a file in the $HOME/.local/share/flashcards directory.

They have a csv structure
prompt,answer,lastseen,delay

for example
```bash
When was the moonlanding?,1959,2022-04-13,2

these will be used in the obvious manner.


Example use:


Choose a deck out of (1) memory\_system (2) history\_facts:

2

"Who won the battle of hastings?
type r to reveal"

r

"Normandy
did you get this correct? (N/y)"

y

"Adding weeks delay to card. This will be avaliable to be asked again on 2023-02-3. It is the 3rd time you got this correct"

"What caused WW1?"
```
