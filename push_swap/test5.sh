#!/bin/bash

NUMS=(0 1 2 3 4)

permute () {
    local prefix="$1"
    shift
    local rest=("$@")

    if [ ${#rest[@]} -eq 0 ]; then
        args=$(echo "$prefix" | xargs)
        count=$(./push_swap $args | wc -l)
        echo "$args -> $count instructions"
        return
    fi

    for i in "${!rest[@]}"; do
        permute "$prefix ${rest[$i]}" "${rest[@]:0:$i}" "${rest[@]:$((i+1))}"
    done
}

permute "" "${NUMS[@]}"
