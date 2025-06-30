🤖 X1R ChatBot – text to Voice-Controlled Virtual Assistant


Welcome to X1R ChatBot, an AI-powered  assistant built using C, and SQLite. It provides a rich command-line and optional chat-based frontend for users to interact using both keyboard and voice.

<br>

🎯 Key Capabilities

<br>


Personalized greetings




Math operations




Google search (sports, jobs, coding problems)




Recent command history




Voice feedback (WAV files)




Speech recognition (Python-based) advance


Mostly in C Programming


SQLite logging of commands
FOR AN DATA BASE OR PREVIOUS RECORD ADD IN BACKED


<br>

📸 Project Preview

<br>
(Insert image link if needed)
<br>
<br>

💡 Feature Summary

<br>


✅ Voice-activated Greeting




✅ Google Search Integration IN FUTURE




✅ Math Operation Engine




✅ Command History Sidebar




✅ Voice Feedback (WAV)




✅ Python-based Speech Recognition But in c programing




✅ SQLite Logging Support




✅ Secure Activation Code



<br>

📁 Core Project Structure

<br>
X1RChatBot/<br><br>
├── main.c  <br>                # Core assistant logic
├── listener.py   <br>          # Speech recognition in Python
├── app.py                  # Flask web interface
├── templates/index.html    # Chat frontend
├── static/style.css        # Chat styling
├── command.txt             # Bridge file (voice → C)
├── sqlite3.c / sqlite3.h   # SQLite C integration
├── x1r_logs.db             # SQLite DB file
└── README.md               # Project documentation



<br>
🧪 Sample Commands
<br>

search sport
find job
code problem
math
exit


<br>

🔧 How to Build & Run
<br>

Requirements




🖥️ Windows OS




💻 GCC or Code::Blocks


<br>

🔊 WAV files for voice


<br>

🐍 Python 3 with:
c integration code in that



text colletive-Recognition




pyttsx3 advance




Flask advance






Install Python Packages


pip install SpeechRecognition pyttsx3 flask


<br>
Compile C Program

<br>
gcc main.c sqlite3.c -o X1R.exe -lwinmm


<br>
Run Flask Web App
<br>

python app.py
<br>

<br>
Visit: http://localhost:5000
<br>


🔄 Voice Input Script (Python)

<br>
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
<br>


<br>
🗃️ SQLite Integration (C)
<br>

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

<br>

💬 Chat-Style Frontend (Optional)
<br><br>

index.html
<br>

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


<br>
style.css
<br>

body { background: #121212; color: #fff; font-family: Arial; padding: 20px; }
.chat-container { background: #1e1e1e; padding: 20px; border-radius: 10px; max-width: 600px; margin: auto; }
#chat-box { height: 300px; overflow-y: scroll; background: #2c2c2c; padding: 10px; margin-bottom: 10px; }
input[type="text"] { width: 80%; padding: 10px; }
button { padding: 10px; background: #0f62fe; color: white; border: none; }
<br>

<br>
app.py
<br>

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

<br>
<br>

🧠 How It All Works

<br>


User types or speaks a command




Python saves it to command.txt




C reads it, performs actions (search, math, speech, etc.)




Logs are saved in x1r_logs.db




Chat UI reloads with updated history




<br>
👥 Project Team

<br>


Neeraj Kumar – 2300331540068




Shivansh Srivastava – 2300331540100




Rishant Singh – 2300331540085




Vansh – 2300331540118


<br>

🎓 CSE (Data Science) — RKGIT Ghaziabad

🗓️ Session: 2024–25
<br>

<br>
🏅 Acknowledgments
<br>

Submitted for the partial fulfillment of B.Tech Degree under supervision of:




👩‍🏫 Mrs. Bhawna Goel




👩‍🏫 Mrs. Pooja Chaudhary




👨‍🏫 Dr. Preeti Sharma (HoD)



<br>

📜 License
<br>

This project is for academic use only. Do not redistribute without permission.



📬 Contact


📧 neerajkr.17115@gmail.com

🔗 GitHub


<br>
📺 Bonus YouTube Resources
<br>



📊 SQLite + Python Tutorial




🎨 Flask GUI Playlist


