### 16/10/2026

- traceroute use increasing TTL (1 to X) through ICMP packet to know and get every router and we can know we arrived at the end of the "hops" when the output is "*".
``` shell
 ➜  ft_ping git:(master) ✗ traceroute google.fr   
traceroute to google.fr (172.217.22.163), 64 hops max, 40 byte packets
 1  10.18.254.254 (10.18.254.254)  5.239 ms  4.116 ms  4.579 ms
 2  10.60.1.1 (10.60.1.1)  4.086 ms  10.683 ms  8.341 ms
 3  81.255.67.30 (81.255.67.30)  3.708 ms *  13.250 ms
 4  81.54.107.41 (81.54.107.41)  51.548 ms  4.277 ms  5.000 ms
 5  lag-44.mso2-ig2.montsouris.transitip.raei.francetelecom.net (81.52.85.198)  8.309 ms
    lag-43.bjn1-ig2.beaujon.transitip.raei.francetelecom.net (81.52.85.210)  8.049 ms
    lag-44.mso2-ig2.montsouris.transitip.raei.francetelecom.net (81.52.85.198)  8.087 ms
 6  193.252.137.233 (193.252.137.233)  8.876 ms
    193.252.137.229 (193.252.137.229)  7.953 ms
    193.252.137.233 (193.252.137.233)  8.401 ms
 7  *^C
➜  ft_ping git:(master) ✗ 
```

My first idea is to take some building blocks from my other project ft_ping :
- hostname resolution
- raw ICMP sockets
- packet checksums
- timing
- parsing ICMP error messages

The main change will be the probe loop, ping sends Echo Requests at a fixed TTL and waits for an Echo Reply, traceroute needs to send probes with increasing TTL values, report the router and rtt(round-trip time) for each TTL, and stop when a probe reaches the destination. I'll also need to match each ICMP error to the probe it quotes.