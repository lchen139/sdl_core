package com.ford.syncV4.protocol.heartbeat;

import android.test.InstrumentationTestCase;

import com.ford.syncV4.proxy.rpc.TestCommon;

import org.mockito.Matchers;
import org.mockito.Mockito;

import static com.ford.syncV4.protocol.heartbeat.IHeartbeatMonitor.IHeartbeatMonitorDelegate;
import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.MatcherAssert.assertThat;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.timeout;
import static org.mockito.Mockito.verify;

/**
 * Tests for HeartbeatMonitor class.
 *
 * Created by enikolsky on 2013-12-26.
 */
public class HeartbeatMonitorTest extends InstrumentationTestCase {
    private static final int MAX_TIMER_DRIFT = 20;
    private static final int HEARTBEAT_TEST_INTERVAL = 30;
    private IHeartbeatMonitorDelegate delegateMock;
    private HeartbeatMonitor heartbeatMonitor;

    @Override
    public void setUp() throws Exception {
        super.setUp();
        TestCommon.setupMocking(this);

        delegateMock = Mockito.mock(IHeartbeatMonitorDelegate.class);
        heartbeatMonitor = new HeartbeatMonitor();
    }

    @Override
    public void tearDown() throws Exception {
        delegateMock = null;
        heartbeatMonitor = null;

        super.tearDown();
    }

    public void testDelegateShouldBeSet() {
        heartbeatMonitor.setDelegate(delegateMock);
        assertThat(heartbeatMonitor.getDelegate(), is(delegateMock));
    }

    public void testStartedMonitorShouldAskToSendHeartbeatAfterTimeout()
            throws InterruptedException {
        heartbeatMonitor.setDelegate(delegateMock);

        heartbeatMonitor.setInterval(HEARTBEAT_TEST_INTERVAL);
        heartbeatMonitor.start();

        verify(delegateMock, timeout(HEARTBEAT_TEST_INTERVAL + MAX_TIMER_DRIFT))
                .sendHeartbeat(heartbeatMonitor);
        heartbeatMonitor.stop();
    }

    public void testStartedAndStoppedMonitorShouldNotSendHeartbeats()
            throws InterruptedException {
        heartbeatMonitor.setDelegate(delegateMock);

        heartbeatMonitor.setInterval(HEARTBEAT_TEST_INTERVAL);
        heartbeatMonitor.start();
        Thread.sleep(5);
        heartbeatMonitor.stop();

        // this does not work:
//        verify(delegateMock, timeout(HEARTBEAT_TEST_INTERVAL * 3 +
//                MAX_TIMER_DRIFT).never()).sendHeartbeat(
//                Matchers.<IHeartbeatMonitor>any());

        Thread.sleep(HEARTBEAT_TEST_INTERVAL * 2 + MAX_TIMER_DRIFT);
        verify(delegateMock, never()).sendHeartbeat(
                Matchers.<IHeartbeatMonitor>any());
    }

    public void testStartedAndStoppedImmediatelyMonitorShouldNotSendHeartbeats()
            throws InterruptedException {
        heartbeatMonitor.setDelegate(delegateMock);

        heartbeatMonitor.setInterval(HEARTBEAT_TEST_INTERVAL);
        heartbeatMonitor.start();
        heartbeatMonitor.stop();

        Thread.sleep(HEARTBEAT_TEST_INTERVAL * 2 + MAX_TIMER_DRIFT);
        verify(delegateMock, never()).sendHeartbeat(
                Matchers.<IHeartbeatMonitor>any());
    }

    public void testStartedMonitorShouldSendHeartbeatsRepeatedly()
            throws InterruptedException {
        heartbeatMonitor.setDelegate(delegateMock);

        heartbeatMonitor.setInterval(HEARTBEAT_TEST_INTERVAL);
        heartbeatMonitor.start();

        final int numberOfInvocations = 3;
        verify(delegateMock,
                timeout((HEARTBEAT_TEST_INTERVAL * numberOfInvocations) +
                        MAX_TIMER_DRIFT).times(
                        numberOfInvocations)).sendHeartbeat(heartbeatMonitor);
        heartbeatMonitor.stop();
    }
}
