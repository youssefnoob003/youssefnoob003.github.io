import  sqlite3

conn = sqlite3.connect('opengeo.sqlite')
cur = conn.cursor()

cur.execute("SELECT address FROM Locations")

for row in cur:
    print(row)