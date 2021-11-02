# Zadatak 2. - Napisati skriptu koja ce pronaci sve datoteke promijenjene u
# zadnjih ‘n’minuta (preko argumenata) u “/home/username” direktoriju,
# ispisati i komprimirati u “backup.tgz”.

n=""
read -p "Upisi broj minuta: " n
files=$(find /home/$USERNAME/* -type f -and -newermt $(date -d "$date -$n minutes" +%T) | cat)
echo $files
zip backup.tgz $files
