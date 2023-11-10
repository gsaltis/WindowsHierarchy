set DB=..\Windows2.db

sqlite3 %DB% "DELETE From Windows;"
sqlite3 %DB% "INSERT INTO Windows VALUES(0, 0, 0, 'main', 0);"
sqlite3 %DB% "INSERT INTO Windows VALUES(1000, 1000, 0,    'mainWindow', 0);"
sqlite3 %DB% "INSERT INTO Windows VALUES(2000, 2000, 1000, 'displayWindow', 0);"
sqlite3 %DB% "INSERT INTO Windows VALUES(3000, 3000, 2000, 'hierarchyWindow', 0);"
sqlite3 %DB% "INSERT INTO Windows VALUES(4000, 8000, 2000, 'signalSlotWindow', 0);"
