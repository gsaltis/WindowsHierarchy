set DB=../Windows2.db

sqlite3 %DB% "DELETE From Classes;"
sqlite3 %DB% "INSERT INTO Classes VALUES (1000, 'MainWindow');"
sqlite3 %DB% "INSERT INTO Classes VALUES (2000, 'MainDisplayWindow');"
sqlite3 %DB% "INSERT INTO Classes VALUES (3000, 'WindowHierarchy');"
sqlite3 %DB% "INSERT INTO Classes VALUES (4000, 'WindowHierarchyScrollArea');"
sqlite3 %DB% "INSERT INTO Classes VALUES (5000, 'WindowHierarchyContainer');"
sqlite3 %DB% "INSERT INTO Classes VALUES (6000, 'WindowHierarchyContainer');"
sqlite3 %DB% "INSERT INTO Classes VALUES (7000, 'WindowHierarchyContainerElement');"
sqlite3 %DB% "INSERT INTO Classes VALUES (8000, 'SignalSlotWindow');"

