#!/bin/bash

echo "=========================================="
echo "CPP03 COMPREHENSIVE EVALUATION TEST"
echo "=========================================="

# Test each exercise
for ex in ex00 ex01 ex02 ex03; do
    echo ""
    echo "=== TESTING $ex ==="
    cd $ex
    
    # Clean and compile
    echo "🔨 Compiling..."
    make fclean > /dev/null 2>&1
    if make > /dev/null 2>&1; then
        echo "✅ Compilation: SUCCESS"
    else
        echo "❌ Compilation: FAILED"
        cd ..
        continue
    fi
    
    # Check executable exists
    if [ -f claptrap ]; then
        exe="claptrap"
    elif [ -f fragtrap ]; then
        exe="fragtrap"
    elif [ -f diamondtrap ]; then
        exe="diamondtrap"
    else
        echo "❌ No executable found"
        cd ..
        continue
    fi
    
    # Test execution
    echo "🚀 Testing execution..."
    if timeout 5s ./$exe > /dev/null 2>&1; then
        echo "✅ Execution: SUCCESS"
    else
        echo "❌ Execution: FAILED or TIMEOUT"
    fi
    
    # Check Orthodox Canonical Form
    echo "📋 Checking Orthodox Canonical Form..."
    if grep -q "ClapTrap()" *.hpp && grep -q "~ClapTrap" *.hpp && grep -q "operator=" *.hpp; then
        echo "✅ Orthodox Canonical Form: PRESENT"
    else
        echo "❌ Orthodox Canonical Form: MISSING"
    fi
    
    cd ..
done

echo ""
echo "=========================================="
echo "EVALUATION TEST COMPLETE"
echo "=========================================="
