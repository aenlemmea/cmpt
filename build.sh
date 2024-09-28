clean() {
	mkdir -p ./out
	rm -rf out
	if [ -e compile_commands.json ]; then
		rm compile_commands.json
	fi
	exit 1
}

if [ $# -ge 1 ]; then
	case "$1" in
		"clean")
			clean
			;;
	esac
fi


mkdir -p out && cd out
cmake .. -G "Unix Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=1
mv compile_commands.json ../
