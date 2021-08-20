#include <stdio.h>
#include <vector>
#include <cassert>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MAX_CLIENTS = 100 + 1;
    const int MAX_FILES = 200 + 1;
    int nClients, nFiles;
    scanf("%d %d", &nClients, &nFiles);
    std::vector<int> clientTime(nClients, 0);
    int fullClients = 1;
    std::vector<std::vector<int>> clientHasFiles(nClients);
    std::vector<std::vector<int>> fileOnClients(nFiles);
    std::vector<std::vector<int>> p2pRank(nClients, std::vector<int> (nClients, 0));
    std::vector<std::vector<bool>> hasFile(nClients, std::vector<bool> (nFiles, false));
    for (int iFile = 0; iFile < nFiles; iFile++) {
        clientHasFiles[0].push_back(iFile);
        fileOnClients[iFile].push_back(0);
        hasFile[0][iFile] = true;
    }
    for (int time = 1; ; time++) {
        // pre-round and choose fragment
        // O(n * m)
        std::vector<int> clientWannaFile(nClients, -1);
        for (int iClient = 1; iClient < nClients; iClient++) {
            if (clientTime[iClient] > 0) {
                continue;
            }
            int bestFile = -1;
            int minClientsGive = MAX_CLIENTS;
            for (int iFile = 0; iFile < nFiles; iFile++) {
                if (!hasFile[iClient][iFile] && 
                    (int)fileOnClients[iFile].size() < minClientsGive
                ) {
                    bestFile = iFile;
                    minClientsGive = (int)fileOnClients[iFile].size();
                }
            }
            clientWannaFile[iClient] = bestFile;
        }
        // 1 step. Choose client with wanted file. 1) min files, 2) min index
        // O(n * m)
        std::vector<std::vector<int>> inviteForClient(nClients);
        for (int iClient = 1; iClient < nClients; iClient++) {
            if (clientTime[iClient] > 0) {
                continue;
            }
            int bestClient = 0;
            int minFilesHasSecondClient = MAX_FILES;
            for (int iSecondClient : fileOnClients[clientWannaFile[iClient]]) {
                if ((int) clientHasFiles[iSecondClient].size() < minFilesHasSecondClient) {
                    minFilesHasSecondClient = (int)clientHasFiles[iSecondClient].size();
                    bestClient = iSecondClient;
                } else if ((int) clientHasFiles[iSecondClient].size() == minFilesHasSecondClient && 
                    iSecondClient < bestClient
                ) {
                    bestClient = iSecondClient;
                }
            }
            inviteForClient[bestClient].push_back(iClient);
        } 
        // 2 step. Choose client to accept his invite
        // O(n ^ 2)
        std::vector<int> clientAcceptClient(nClients, -1);
        for (int iClient = 0; iClient < nClients; iClient++) {
            int bestClient = -1;
            int bestRank = -1;
            int minFilesOnClient = MAX_FILES;
            for (int iSecondClient : inviteForClient[iClient]) {
                if (p2pRank[iClient][iSecondClient] > bestRank) {
                    bestRank = p2pRank[iClient][iSecondClient];
                    minFilesOnClient = (int)clientHasFiles[iSecondClient].size();
                    bestClient = iSecondClient;
                } else if (p2pRank[iClient][iSecondClient] == bestRank && 
                    (int)clientHasFiles[iSecondClient].size() < minFilesOnClient
                ) {
                    minFilesOnClient = (int)clientHasFiles[iSecondClient].size();
                    bestClient = iSecondClient;
                } else if (p2pRank[iClient][iSecondClient] == bestRank && 
                    (int)clientHasFiles[iSecondClient].size() == minFilesOnClient &&
                    iSecondClient < bestClient
                ) {
                    bestClient = iSecondClient;
                }
            }
            clientAcceptClient[iClient] = bestClient;
        }
        // 3 step. update info
        // O(n)
        for (int iClient = 0; iClient < nClients; iClient++) {
            if (clientAcceptClient[iClient] == -1) {
                continue;
            }
            int iSecondClient = clientAcceptClient[iClient];
            int file = clientWannaFile[iSecondClient];
            p2pRank[iSecondClient][iClient]++;
            clientHasFiles[iSecondClient].push_back(file);
            hasFile[iSecondClient][file] = true;
            fileOnClients[file].push_back(iSecondClient);
            if ((int)clientHasFiles[iSecondClient].size() == nFiles) {
                clientTime[iSecondClient] = time;
                fullClients++;
            }
        }
        if (fullClients == nClients) {
            for (int iClient = 1; iClient < nClients; iClient++) {
                printf("%d ", clientTime[iClient]);
            }
            break;
        }
    }
    return 0;
}
