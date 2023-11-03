/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:00:50 by jofoto            #+#    #+#             */
/*   Updated: 2023/11/03 20:15:30 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/* void	init_udp_com(int *sockfd, struct sockaddr_in *serverAddr)
{
	*sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0)
	{
		write(2, "Socket Error\n", 14);
		exit(2);
	}
	
	memset(serverAddr, 0, sizeof(*serverAddr));
	serverAddr->sin_family = AF_INET;
	serverAddr->sin_port = htons(SERVER_PORT);
	if (inet_pton(AF_INET, SERVER_IP, &(serverAddr->sin_addr) <= 0)) {
		write(2, "inet_pton Error\n", 17);
		exit(1);
	}
	if (sendto(*sockfd, "start", 5, 0, (struct sockaddr*)serverAddr, sizeof(*serverAddr)) < 0) {
		write(2, "Sendto Failed\n", 15);
		close(*sockfd);
		exit(1);
	}
} */

void	*routine(void *data)
{
	t_data	*d;
	int		sockfd;
	struct	sockaddr_in serverAddr;
	socklen_t serverAddrLen;
	float angles[2];

	d = (t_data *)data;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0)
	{
		write(2, "Socket Error\n", 14);
		exit(2);
	}
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERVER_PORT);
	if (inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr) <= 0) {
		write(2, "inet_pton Error\n", 17);
		exit(1);
	}
	if (sendto(sockfd, "start", 5, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
		write(2, "Sendto Failed\n", 15);
		close(sockfd);
		exit(1);
	}
	serverAddrLen = sizeof(serverAddr);
	while(1)
	{
		memset(angles, 0, sizeof(angles));
		if (recvfrom(sockfd, angles, sizeof(angles), 0, (struct sockaddr*)&serverAddr, &serverAddrLen) >= 0) {
			d->angle.y = angles[0];
			d->angle.x = angles[1] + 90;
		}
	}
}
