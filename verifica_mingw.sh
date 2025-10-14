#!/usr/bin/bash
echo "=============================================="
echo "🔍 Verificação do ambiente MinGW / GCC (MSYS2)"
echo "=============================================="

# Detecta terminal ativo
if [[ "$MSYSTEM" == "MINGW64" ]]; then
    echo "✅ Terminal ativo: MINGW64 (64 bits)"
elif [[ "$MSYSTEM" == "MINGW32" ]]; then
    echo "⚠️  Terminal ativo: MINGW32 (32 bits)"
    echo "   👉 Recomenda-se usar o 'MSYS2 MinGW64' para 64 bits."
elif [[ "$MSYSTEM" == "MSYS" ]]; then
    echo "❌ Terminal ativo: MSYS (apenas manutenção)"
    echo "   ❗ Abra o terminal correto: 'MSYS2 MinGW64'"
else
    echo "❓ Terminal desconhecido: $MSYSTEM"
fi

echo
echo "📁 Verificando PATH..."
echo "$PATH" | tr ':' '\n' | grep mingw64 | sed 's/^/   - /'
echo

# Verifica instalação do GCC
echo "🧩 Verificando GCC..."
if command -v gcc >/dev/null 2>&1; then
    echo "✅ GCC encontrado: $(command -v gcc)"
    echo "📦 Versão:"
    gcc -v 2>&1 | grep "gcc version"
else
    echo "❌ GCC não encontrado."
    echo "   Para instalar o compilador, execute:"
    echo "   pacman -S mingw-w64-x86_64-gcc"
fi

echo
echo "🧱 Teste rápido de compilação..."
echo '#include <stdio.h>' > test.c
echo 'int main(){printf("Compilador funcionando!\\n");return 0;}' >> test.c

if gcc test.c -o test.exe 2>/dev/null; then
    echo "✅ Compilação bem-sucedida!"
    ./test.exe
    rm -f test.c test.exe
else
    echo "❌ Erro na compilação. Verifique o ambiente."
fi

echo
echo "=============================================="
echo "✅ Verificação concluída."
echo "=============================================="
