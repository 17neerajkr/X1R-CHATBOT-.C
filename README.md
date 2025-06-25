🤖 X1R ChatBot – TEXT-Controlled Virtual Assistant


Welcome to X1R ChatBot, an AI-powered, voice-controlled assistant designed using C language, Windows APIs, Python, and SQLite. It provides an intelligent and interactive command-line interface that supports:




🎯 Personalized greetings




🧠 Math operations




🌐 Google job/sport/code search




🗂️ Recent command history




🔊 Voice feedback (WAV sounds)




🔊 Speech recognition input (Python-based)




📂 SQLite-powered command logging





📸 Project Preview






💡 Features




✅ Voice-activated Greeting




✅ Google Search (Jobs, Sports, Coding Problems)




✅ Math Calculation Engine




✅ Search Sidebar (Recent Commands)




✅ WAV Sound Feedback for Interaction




✅ Python Speech-to-Text Integration




✅ SQLite Command Logging




✅ Activation Code Security





📂 Project Structure
<br>


X1RChatBot/
├── main.c                # Core assistant code
├── listener.py           # Speech recognition via Python
├── sounds/               # WAV files for responses
├── command.txt           # Voice input file from Python
├── sqlite3.c/h           # SQLite DB source files
├── x1r_logs.db           # SQLite database
├── README.md             # This file
├── X1RChatBot_removed.pdf# Project documentation
└── assets/               # Images/screenshots (optional)




🧪 Sample Commands


> search sport
> find job
> code problem
> math
> exit




🔧 How to Build & Run


🛠️ Requirements




🖥️ Windows OS




💻 C Compiler (GCC or Code::Blocks)




🗉 WinMM library (-lwinmm)




🔈 WAV sound files




🔐 Python 3 (for speech recognition)




🔹 Python packages: SpeechRecognition, pyttsx3




🏐 Install Python Dependencies


pip install SpeechRecognition pyttsx3



🏠 Compile C Code


gcc main.c sqlite3.c -o X1R.exe -lwinmm



▶️ Run Program


./X1R.exe




🔄 Python + C Integration (Voice Input)


listener.py (Speech Input Script)


import speech_recognition as sr

def get_voice_input():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("🎤 Listening...")
        audio = r.listen(source)
    try:
        command = r.recognize_google(audio)
        print(f"You said: {command}")
        with open("command.txt", "w") as f:
            f.write(command)
    except sr.UnknownValueError:
        print("Could not understand audio")

get_voice_input()



Update main.c to Replace Input


system("python listener.py");
FILE *f = fopen("command.txt", "r");
if (f != NULL) {
    fgets(input, sizeof(input), f);
    input[strcspn(input, "\n")] = 0;
    fclose(f);
}




📊 SQLite Integration


Initialize and Log Commands in main.c


#include "sqlite3.h"

void initDB() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc = sqlite3_open("x1r_logs.db", &db);
    if (!rc) {
        const char *sql = "CREATE TABLE IF NOT EXISTS history (id INTEGER PRIMARY KEY, command TEXT, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";
        sqlite3_exec(db, sql, 0, 0, &errMsg);
        sqlite3_close(db);
    }
}

void logCommandToDB(const char *command) {
    sqlite3 *db;
    char *errMsg = 0;
    sqlite3_open("x1r_logs.db", &db);
    char sql[512];
    snprintf(sql, sizeof(sql), "INSERT INTO history (command) VALUES ('%s');", command);
    sqlite3_exec(db, sql, 0, 0, &errMsg);
    sqlite3_close(db);
}



Call initDB(); at the start of main() and logCommandToDB(input); after taking input.



👥 Project Team

<strong>Team Members</strong><br>



Name
Roll Number




Neeraj Kumar
2300331540068


Shivansh Srivastava
2300331540100


Rishant Singh
2300331540085


Vansh
2300331540118




🎓 CSE (Data Science)

🏫 Raj Kumar Goel Institute of Technology, Ghaziabad

🗓️ Session: 2024-25



📃 Certificate & Acknowledgment


This project was submitted in partial fulfillment of the award of Bachelor of Technology, under the supervision of:




👩‍🏫 Mrs. Bhawna Goel




👩‍🏫 Mrs. Pooja Chaudhary




👨‍🏫 Dr. Preeti Sharma (HoD)





📜 License


This project is for academic purposes only. Please do not redistribute or reuse code without permission.



🌐 Connect




📧 neerajkr.17115@gmail.com




🔗 GitHub: github.com/17neerajkr/X1RChatBot


YOUTUBE SECTION THAT HELP FOR AN DATABASE AND GUI DESIGN :
 ( DATA BASE ) https://youtu.be/mzajT85YNhs?si=goQwiqf57-UMB51r
( GUI ) https://youtube.com/playlist?list=PLEs_0O72adQBUpcPJv7dKaElGwyzVljtk&si=c0musUgGBQR2T8ki


\\\\\\\\\\\\    You want to add a simple frontend UI (like ChatGPT) to your existing X1R ChatBot so it:  \\\\\\\\




🧑‍💻 Acts like a chat interface




🧠 Shows past command history (searching, math, jobs, etc.)




✍️ Can input a new command




📦 Communicates with the backend (C/Python/DB)





✅ Let’s Build a Simple Frontend (Web-Based)


🔧 Tech Stack:


LayerTool/LanguagePurposeUI (frontend)HTML + CSS + JSChat-like interfaceBackendPython (Flask)Connect UI with C or SQLite DBProcessingYour existing C AppHandles logic + speech + searchDatabaseSQLiteStores history / logs


🧱 Folder Structure





X1RChatBot/
├── static/
│   └── style.css
├── templates/
│   └── index.html
├── command.txt
├── x1r_logs.db
├── main.c
├── listener.py
├── app.py          <-- 🧠 Python Flask server
└── README.md




📄 index.html (Chat Style UI)





<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>X1R ChatBot</title>
  <link rel="stylesheet" href="/static/style.css" />
</head>
<body>
  <div class="chat-container">
    <h2>X1R ChatBot 💬</h2>
    <div id="chat-box">
      {% for entry in history %}
        <div class="chat-entry">{{ entry[2] }} ➤ {{ entry[1] }}</div>
      {% endfor %}
    </div>
    <form action="/" method="POST">
      <input type="text" name="command" placeholder="Type your command..." required />
      <button type="submit">Send</button>
    </form>
  </div>
</body>
</html>




🎨 style.css (Basic Chat Styling)





body {
  font-family: Arial, sans-serif;
  background: #121212;
  color: #fff;
  padding: 20px;
}
.chat-container {
  max-width: 600px;
  margin: auto;
  background: #1e1e1e;
  border-radius: 10px;
  padding: 20px;
}
#chat-box {
  height: 300px;
  overflow-y: scroll;
  background: #2c2c2c;
  padding: 10px;
  margin-bottom: 10px;
}
.chat-entry {
  margin: 5px 0;
}
input[type="text"] {
  width: 80%;
  padding: 10px;
}
button {
  padding: 10px;
  background: #0f62fe;
  color: white;
  border: none;
}




⚙️ app.py (Flask Backend)





from flask import Flask, render_template, request, redirect
import sqlite3
import os

app = Flask(__name__)

def get_history():
    conn = sqlite3.connect("x1r_logs.db")
    c = conn.cursor()
    c.execute("SELECT * FROM history ORDER BY id DESC LIMIT 20")
    data = c.fetchall()
    conn.close()
    return data

@app.route("/", methods=["GET", "POST"])
def home():
    if request.method == "POST":
        cmd = request.form["command"]
        with open("command.txt", "w") as f:
            f.write(cmd)
        os.system("X1R.exe")  # Run your compiled C assistant
        return redirect("/")
    history = get_history()
    return render_template("index.html", history=history)

if __name__ == "__main__":
    app.run(debug=True)




✅ What Happens Behind the Scenes




User types a command in the UI




Flask saves it to command.txt




C program (X1R.exe) runs and:




Reads from command.txt




Performs the action (math/search/voice)




Logs to SQLite






UI reloads with updated history





🚀 To Run It:




Install Flask:













http://localhost:5000
pip install flask





Run the server:



python app.py





Open in browser:






