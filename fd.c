/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:03:31 by frocha-b          #+#    #+#             */
/*   Updated: 2025/05/09 12:06:36 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>  // Para open()
#include <unistd.h> // Para close()
#include <stdio.h>  // Para printf()

int main() {
    int fd = open("teste.txt", O_RDONLY); // Abre o arquivo para leitura

    if (fd == -1) {
        // Tratar erro
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Imprime o file descriptor
    printf("File descriptor de 'meuarquivo.txt': %d\n", fd);

    close(fd); // Fecha o arquivo
    return 0;
}

