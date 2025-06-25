🤖 X1R ChatBot – Voice-Controlled Virtual Assistant


Welcome to X1R ChatBot, an AI-powered  assistant built using C, Python, , and SQLite. It provides a rich command-line and optional chat-based frontend for users to interact using both keyboard and voice.

<br>

🎯 Key Capabilities

<br>


Personalized greetings




Math operations




Google search (sports, jobs, coding problems)




Recent command history




Voice feedback (WAV files)




Speech recognition (Python-based)




SQLite logging of commands





📸 Project Preview


(Insert image link if needed)



💡 Feature Summary




✅ Voice-activated Greeting




✅ Google Search Integration




✅ Math Operation Engine




✅ Command History Sidebar




✅ Voice Feedback (WAV)




✅ Python-based Speech Recognition




✅ SQLite Logging Support




✅ Secure Activation Code





📁 Core Project Structure


X1RChatBot/
├── main.c                  # Core assistant logic
├── listener.py             # Speech recognition in Python
├── app.py                  # Flask web interface
├── templates/index.html    # Chat frontend
├── static/style.css        # Chat styling
├── command.txt             # Bridge file (voice → C)
├── sqlite3.c / sqlite3.h   # SQLite C integration
├── x1r_logs.db             # SQLite DB file
└── README.md               # Project documentation




🧪 Sample Commands


search sport
find job
code problem
math
exit




🔧 How to Build & Run


Requirements




🖥️ Windows OS




💻 GCC or Code::Blocks




🔊 WAV files for voice




🐍 Python 3 with:




SpeechRecognition




pyttsx3




Flask






Install Python Packages


pip install SpeechRecognition pyttsx3 flask



Compile C Program


gcc main.c sqlite3.c -o X1R.exe -lwinmm



Run Flask Web App


python app.py



Visit: http://localhost:5000



🔄 Voice Input Script (Python)


import speech_recognition as sr

def get_voice_input():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("🎤 Listening...")
        audio = r.listen(source)
    try:
        command = r.recognize_google(audio)
        with open("command.txt", "w") as f:
            f.write(command)
    except:
        print("Could not understand audio")

get_voice_input()




🗃️ SQLite Integration (C)


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



Use initDB(); at startup and logCommandToDB(input); after reading user input.



💬 Chat-Style Frontend (Optional)


index.html


<title>X1R ChatBot</title>
<div class="chat-container">
  <h2>X1R ChatBot 💬</h2>
  <div id="chat-box">
    {% for entry in history %}
      <div class="chat-entry">{{ entry[2] }} ➤ {{ entry[1] }}</div>
    {% endfor %}
  </div>
  <form action="/" method="POST">
    <input type="text" name="command" placeholder="Type your command...">
    <button type="submit">Send</button>
  </form>
</div>



style.css


body { background: #121212; color: #fff; font-family: Arial; padding: 20px; }
.chat-container { background: #1e1e1e; padding: 20px; border-radius: 10px; max-width: 600px; margin: auto; }
#chat-box { height: 300px; overflow-y: scroll; background: #2c2c2c; padding: 10px; margin-bottom: 10px; }
input[type="text"] { width: 80%; padding: 10px; }
button { padding: 10px; background: #0f62fe; color: white; border: none; }



app.py


from flask import Flask, render_template, request, redirect
import sqlite3, os

app = Flask(__name__)

def get_history():
    conn = sqlite3.connect("x1r_logs.db")
    c = conn.cursor()
    c.execute("SELECT * FROM history ORDER BY id DESC LIMIT 20")
    return c.fetchall()

@app.route("/", methods=["GET", "POST"])
def home():
    if request.method == "POST":
        cmd = request.form["command"]
        with open("command.txt", "w") as f:
            f.write(cmd)
        os.system("X1R.exe")
        return redirect("/")
    return render_template("index.html", history=get_history())

if __name__ == "__main__":
    app.run(debug=True)




🧠 How It All Works




User types or speaks a command




Python saves it to command.txt




C reads it, performs actions (search, math, speech, etc.)




Logs are saved in x1r_logs.db




Chat UI reloads with updated history





👥 Project Team




Neeraj Kumar – 2300331540068




Shivansh Srivastava – 2300331540100




Rishant Singh – 2300331540085




Vansh – 2300331540118




🎓 CSE (Data Science) — RKGIT Ghaziabad

🗓️ Session: 2024–25



🏅 Acknowledgments


Submitted for the partial fulfillment of B.Tech Degree under supervision of:




👩‍🏫 Mrs. Bhawna Goel




👩‍🏫 Mrs. Pooja Chaudhary




👨‍🏫 Dr. Preeti Sharma (HoD)





📜 License


This project is for academic use only. Do not redistribute without permission.



📬 Contact


📧 neerajkr.17115@gmail.com

🔗 GitHub



📺 Bonus YouTube Resources




📊 SQLite + Python Tutorial




🎨 Flask GUI Playlist


