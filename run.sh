while inotifywait -e close_write main.c
do
    #python main.py
	make
    eog output.png
done
