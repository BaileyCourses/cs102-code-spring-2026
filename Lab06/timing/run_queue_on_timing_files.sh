
g++ -o queue queue.cpp
for c in timing/queue2to*.txt; do
	echo -e "\n==============================================\n"
	echo -en "Running ${c}...\n"
	./queue "${c}"
done
