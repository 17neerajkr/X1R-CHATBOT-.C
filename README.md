🤖 X1R ChatBot – text-Controlled Virtual Assistant


Welcome to X1R ChatBot, an AI-powered, voice-controlled assistant designed using:




C language




Windows APIs




Python (for speech)




SQLite (for command history)




It provides an intelligent and interactive command-line interface that supports:




🎯 Personalized greetings




🧠 Math operations




🌐 Google job/sport/code search




🗂️ Recent command history




🔊 Voice feedback (WAV sounds)




🎤 Speech recognition input




🗃️ SQLite-powered command logging





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


X1RChatBot/
├── main.c                  # Core assistant logic
├── listener.py             # Speech recognition in Python
├── app.py                  # Flask web interface
├── templates/index.html    # Chat frontend
├── static/style.css        # Chat styling
├── command.txt             # Bridge file between Python and C
├── sqlite3.c / sqlite3.h   # SQLite source
├── x1r_logs.db             # SQLite database file
├── README.md               # This file
└── assets/                 # Optional images/sounds




🧪 Sample Commands


> search sport
> find job
> code problem
> math
> exit




🔧 How to Build & Run


🛠️ Requirements




🖥️ Windows OS




💻 C Compiler (e.g., GCC or Code::Blocks)




🔈 WAV files




🔐 Python 3 with:




SpeechRecognition




pyttsx3




Flask






📦 Install Dependencies


pip install SpeechRecognition pyttsx3 flask



⚙️ Compile the C Code


gcc main.c sqlite3.c -o X1R.exe -lwinmm



▶️ Run the Web UI


python app.py



Visit http://localhost:5000



🧠 Voice Input Script (listener.py)


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
        print("Couldn't understand")

get_voice_input()




🗂️ SQLite Integration in main.c


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



Call initDB(); at the start and logCommandToDB(input); after reading the command.



👨‍💻 About Me


Hi, I'm Neeraj Kumar 👋

💻 Computer Engineering student @ RKGIT (Data Science)

📊 Specializing in C Programming, Power BI, and Frontend Tech

🎖️ 4⭐ C (HackerRank) | Active Blogger | ChatBot Dev (X1R)

🌟 Building practical, voice-driven interfaces with logic + design


📧 neerajkr.17115@gmail.com

🔗 GitHub | LinkedIn



👥 Project Team


Neeraj Kumar            2300331540068
Shivansh Srivastava     2300331540100
Rishant Singh           2300331540085
Vansh                   2300331540118



🎓 CSE (Data Science)

🏫 Raj Kumar Goel Institute of Technology, Ghaziabad

🗓️ 2024–25



📃 Certificate & Acknowledgment


Submitted for the award of Bachelor of Technology under:




👩‍🏫 Mrs. Bhawna Goel




👩‍🏫 Mrs. Pooja Chaudhary




👨‍🏫 Dr. Preeti Sharma (HoD)





📜 License


This project is for academic purposes only. Please do not reuse without permission.



📺 Bonus Resources




🧠 SQLite + Python: https://youtu.be/mzajT85YNhs




🎨 Flask GUI Playlist: https://youtube.com/playlist?list=PLEs_0O72adQBUpcPJv7dKaElGwyzVljtk


