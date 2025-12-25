# CPP_Music_Manager
# Music Manager (Data Structures Project)

A high-performance, console-based Music Management System implemented in C++ from scratch. This project was developed as part of a Data Structures course to demonstrate efficient memory management and algorithmic optimization without relying on the Standard Template Library (STL).

## 🚀 Overview
This application allows users to manage artists, songs, and playlists through a command-line interface. It focuses on optimizing time complexity for search and storage operations using advanced data structures.

## 🛠 Technical Highlights & Data Structures
The core challenge of this project was to implement all data structures manually to ensure maximum optimization and deep understanding of the underlying mechanics:

* **Sparse Set:** Used to store and manage **Artists** for $O(1)$ lookup, insertion, and deletion, ensuring efficient access even with a large number of artists.
* **Suffix Array:** Implemented to handle **lyrics search**. This allows the system to find specific words or phrases within song lyrics with a time complexity of $O(m \log n)$.
* **In-Place Quick Sort:** Used to sort songs within playlists by release year without using auxiliary memory.
* **Circular Queue (Array-based):** Implemented to manage the **playback queue** for handling consecutive playlist execution.
* **Linked Lists:** Utilized for storing collections of songs per artist.
* **Binary Search:** Applied for efficiently locating playlists by ID.

## ✨ Key Features
* **Artist Management:** Add, delete, and search for artists by unique IDs.
* **Song Management:**
    * Add songs with metadata (Name, ID, Release Year, Lyrics).
    * **Full-Text Search:** Find the occurrence and frequency of specific words inside song lyrics using Suffix Arrays.
* **Playlist System:**
    * Create and manage custom playlists.
    * Add/Remove songs.
    * View playlists sorted chronologically (using Quick Sort).
* **Playback Queue:** Queue up multiple playlists for sequential "playback."

## 💻 Tech Stack
* **Language:** C++
* **Constraints:** No STL (Standard Template Library) or pre-built algorithms allowed. All structures (Vector, List, String, etc.) are custom implementations.
* **Paradigm:** Object-Oriented Programming (OOP).

## 📝 Usage
The application runs via a console interface accepting commands such as:
* `adds <name>` : Add an artist.
* `addms <details>` : Add a song with multi-line lyrics.
* `search <artist_id> <music_id> <word>` : Search for a word in a track's lyrics.
* `showp <playlist_id>` : Display a sorted playlist.
* `addqp <id>` : Add a playlist to the playback queue.

---
*This project demonstrates proficiency in low-level memory management, algorithm design, and custom data structure implementation.*
