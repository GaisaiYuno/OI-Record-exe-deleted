while true; do
	./gen > data.in
	./t1 < data.in > my.out
	./std < data.in > std.out
	if diff std.out my.out; then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
done
