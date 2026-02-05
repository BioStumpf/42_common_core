#!/bin/bash

nums=(0 1 2 3 4)

permute() {
    local prefix="$1"
    shift
    local rest=("$@")

    if [ ${#rest[@]} -eq 0 ]; then
        ARG="$prefix"
        result=$(./push_swap $ARG | ./checker_linux $ARG)
        if [ "$result" != "OK" ]; then
            echo "❌ FAIL for: $ARG"
            echo "Result: $result"
            exit 1
        fi
        echo "✅ OK for: $ARG"
        return
    fi

    for i in "${!rest[@]}"; do
        permute "$prefix ${rest[i]}" "${rest[@]:0:i}" "${rest[@]:i+1}"
    done
}

permute "" "${nums[@]}"

echo "🎉 All permutations passed!"

