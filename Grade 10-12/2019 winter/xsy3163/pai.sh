while true; do
	./gen > gen.in
	./t1 < gen.in > my.out
	./std < gen.in > std.out
	if diff std.out my.out; then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
done
