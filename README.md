This is a cli app written in X

It is a minimalist study app that allows you to select a deck of flashcards and study them.
You get shown the prompt, then can reveal the answer.
You get the option to say if you got it correct or not.

If it was correct, it will mark it to be asked again in a few minutes.
If you get it correct again, it will ask you again in a day.
If it is correct again, it will ask you again in a week.
If you are correct again, it will ask you again in a month.

If you get something incorrect, it will reset it to be asked again immedately.

Each deck is a subdirectory in the $HOME/.local/share/flashcards directory.

The deck folder name is what shows up in the app.
Inside are several textfiles for each question.
They have the json structure
{
"prompt":,
"answer":,
"lastseen":,
"delay":,
}

for example
{
"prompt":"When was the moonlanding?",
"answer":"1959",
"lastseen":"2022-04-13",
"delay":"2",
}

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
