# Zadatak 6. - Napisati skriptu koja ce pronaci sve datoteke vece od
# definirane velicine (preko argumenata) u “/home/username” direktoriju,
#  ispisati i komprimirati u “backup.tgz”.

n=""
read -p "Upisi broj bajtova: " n
files=$(find /home/$(echo $USERNAME)/* -type f -size +${n}c)
zip backup.tgz $files
