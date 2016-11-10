{
  teb->Draw("g3.runNumber >> timeAll(1000,0,1000)", "", "");
  teb->Draw("g3.runNumber >> time0(1000,0,1000)", "g3.xtals.chn.eRaw > 2080 && g3.xtals.chn.eRaw < 2180 && g3.xtals.chn.segNum == 0", "");
  teb->Draw("g3.runNumber >> time1(1000,0,1000)", "g3.xtals.chn.eRaw > 2270 && g3.xtals.chn.eRaw < 2370 && g3.xtals.chn.segNum == 1", "");
  teb->Draw("g3.runNumber >> time2(1000,0,1000)", "g3.xtals.chn.eRaw > 2273 && g3.xtals.chn.eRaw < 2373 && g3.xtals.chn.segNum == 2", "");
  teb->Draw("g3.runNumber >> time3(1000,0,1000)", "g3.xtals.chn.eRaw > 2177 && g3.xtals.chn.eRaw < 2277 && g3.xtals.chn.segNum == 3", "");
  teb->Draw("g3.runNumber >> time4(1000,0,1000)", "g3.xtals.chn.eRaw > 2300 && g3.xtals.chn.eRaw < 2400 && g3.xtals.chn.segNum == 4", "");
  teb->Draw("g3.runNumber >> time5(1000,0,1000)", "g3.xtals.chn.eRaw > 2336 && g3.xtals.chn.eRaw < 2436 && g3.xtals.chn.segNum == 5", "");
  teb->Draw("g3.runNumber >> time8(1000,0,1000)", "g3.xtals.chn.eRaw > 2061 && g3.xtals.chn.eRaw < 2161 && g3.xtals.chn.segNum == 8", "");
  teb->Draw("g3.runNumber >> time9(1000,0,1000)", "g3.xtals.chn.eRaw > 2257 && g3.xtals.chn.eRaw < 2357 && g3.xtals.chn.segNum == 9", "");
  teb->Draw("g3.runNumber >> time10(1000,0,1000)", "g3.xtals.chn.eRaw > 2231 && g3.xtals.chn.eRaw < 2331 && g3.xtals.chn.segNum == 10", "");
  teb->Draw("g3.runNumber >> time14(1000,0,1000)", "g3.xtals.chn.eRaw > 2257 && g3.xtals.chn.eRaw < 2357 && g3.xtals.chn.segNum == 14", "");
  teb->Draw("g3.runNumber >> time15(1000,0,1000)", "g3.xtals.chn.eRaw > 2267 && g3.xtals.chn.eRaw < 2367 && g3.xtals.chn.segNum == 15", "");
  teb->Draw("g3.runNumber >> time16(1000,0,1000)", "g3.xtals.chn.eRaw > 2443 && g3.xtals.chn.eRaw < 2543 && g3.xtals.chn.segNum == 16", "");
  teb->Draw("g3.runNumber >> time20(1000,0,1000)", "g3.xtals.chn.eRaw > 2247 && g3.xtals.chn.eRaw < 2347 && g3.xtals.chn.segNum == 20", "");
  teb->Draw("g3.runNumber >> time22(1000,0,1000)", "g3.xtals.chn.eRaw > 2267 && g3.xtals.chn.eRaw < 2367 && g3.xtals.chn.segNum == 22", "");
  teb->Draw("g3.runNumber >> time36(1000,0,1000)", "g3.xtals.chn.eRaw > 2193 && g3.xtals.chn.eRaw < 2293 && g3.xtals.chn.segNum == 36", "");
}
